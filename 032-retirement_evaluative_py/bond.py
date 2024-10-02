import re
import sys


class Bond:
    """Bond calculator"""

    def __init__(self, ROR_filename, start, end, monthly_contribution) -> None:
        if self.__verify_init(ROR_filename, start, end, monthly_contribution):
            self.__start_year, self.__start_month = [int(x) for x in start.strip().split(".")]
            self.__end_year, self.__end_month = [int(x) for x in end.strip().split(".")]
            self.__monthly_contribution = monthly_contribution
            self.__dict_ROR, self.__list_ROR = self.__set_ROR(ROR_filename)
            self.__date_list = self.__set_date_list()
            self.total_ROR_lst = []

    def __verify_init(self, ROR_file, start, end, monthly_contribution):
        try:
            with open(ROR_file, "r") as f:
                f.readlines()
        except FileNotFoundError:
            sys.exit(30)
        if not (isinstance(start, str) and isinstance(end, str)):
            sys.exit(30)
            # raise TypeError("Date must be string")
        if not (self.__valid_date(start) and self.__valid_date(end)):
            sys.exit(30)
            # raise ValueError("Date not valid, must be formed as 'YYYY.MM'")
        start_year, start_month = [int(x) for x in start.strip().split(".")]
        end_year, end_month = [int(x) for x in end.strip().split(".")]
        if start_year > end_year or (start_year == end_year and start_month > end_month):
            sys.exit(10)
            # raise ValueError("start date must be smaller or equal to end date")
        if not (isinstance(monthly_contribution, int) or isinstance(monthly_contribution, float)):
            sys.exit(30)
            # raise TypeError("monthly contribution must be int or float")
        return True

    def __valid_date(self, date):
        pattern = r"^\d{4}\.(0[1-9]|1[0-2])$"
        if re.match(pattern, date):
            return True
        return False
    
    def __validate_date_continuity(self, prev_date, current_date):
        prev_year, prev_month = [int(x) for x in prev_date.strip().split(".")]
        current_year, current_month = [int(x) for x in current_date.strip().split(".")]
        if prev_year > current_year:
            return False
        if prev_year < current_year:
            if not (prev_month==12 and current_month==1):
                return False
        if prev_year == current_year:
            if not (prev_month+1==current_month):
                return False
        return True
            
    def __validate_date_range(self, date_min, date_max):
        min_year, min_month = [int(x) for x in date_min.strip().split(".")]
        max_year, max_month = [int(x) for x in date_max.strip().split(".")]
        min_date = min_year * 100 + min_month
        max_date = max_year * 100 + max_month
        start_date = self.start_year * 100 + self.start_month
        end_date = self.end_year * 100 + self.end_month

        if min_date > start_date or max_date < end_date:
            return False
        return True
    
    def __valid_ROR(self, filename):
        with open(filename, "r") as f:
            lst_lines = [i.strip() for i in f.readlines()]
            prev_date = lst_lines[1].split(",")[0]

            for i in range(len(lst_lines)):
                line = lst_lines[i]
                if i == 0:
                    continue
                if len(line.split(","))!=2:
                    sys.exit(30)
                    # raise ValueError(f"Line {lst_lines.index(line)}: '{line}' is not in correct format")
                date, Ror = line.split(",")
                if not self.__valid_date(date):
                    sys.exit(30)
                    # raise ValueError(f"Line {lst_lines.index(line)}: '{line}' does not have a valid date")
                pattern = r'^\d+(\.\d+)?$'
                if not bool(re.match(pattern, Ror)):
                    sys.exit(30)
                    # raise TypeError(f"Line {lst_lines.index(line)}: '{line}' does not have numeric ROR")
                if not (float(Ror) >= 0):
                    sys.exit(30)
                    # raise ValueError(f"Line {lst_lines.index(line)}: '{line}' does not have a positive ROR")
                if i==1:
                    continue
                if not self.__validate_date_continuity(prev_date,date):
                    sys.exit(30)
                    # raise ValueError(f"Line {lst_lines.index(line)}: '{line}' date not continuous")
                prev_date = date
            
            date_min, date_max = lst_lines[1].split(",")[0], lst_lines[-1].split(",")[0]
            if not self.__validate_date_range(date_min, date_max):
                sys.exit(30)
                # raise ValueError("Date not in the range of provided data")
        return True
    
    def __set_ROR(self, ROR_filename):
        self.__valid_ROR(ROR_filename)
        dict_ROR = {}
        list_ROR = []
        with open(ROR_filename, "r") as f:
            lst_lines = [i.strip() for i in f.readlines()]
            for i in range(len(lst_lines)):
                if i==0:
                    continue
                line = lst_lines[i]
                date, Ror = line.split(",")
                Ror = float(Ror)
                year, month = [int(x) for x in date.strip().split(".")]
                dict_ROR.update({
                        date:{
                            "year": year,
                            "month": month,
                            "Ror": (Ror/1200)
                        }
                    })
                list_ROR.append({
                            "year": year,
                            "month": month,
                            "Ror": Ror/1200
                        })
        return dict_ROR, list_ROR

    def __increase_one_month(self, date):
        year, month = [int(x) for x in date.strip().split(".")]
        if month==12:
            year +=1
            month = 1
            return f"{str(year)}.{str(month).zfill(2)}"
        return f"{str(year)}.{str(month + 1).zfill(2)}"

    def __set_date_list(self):
        total_months = ((self.end_year-self.start_year) * 12) + self.end_month - self.start_month
        start_date=f"{str(self.start_year)}.{str(self.start_month).zfill(2)}"
        date_list = [start_date]
        for i in range(total_months):
            start_date = self.__increase_one_month(start_date)
            date_list.append(start_date)
        return date_list
    
    def __increase_monthly_contribution(self, rate):
        self.__monthly_contribution *= (1 + (rate / 100))

    def calculate_plan(self):
        dict_ROR = self.dict_ROR
        if dict_ROR is None:
            sys.exit(30)
            # raise ValueError("Empty file")
        prev_year = self.date_list[0].split(".")[0]
        balance = 100
        result = []
        total_ROR_lst = []
        for date in self.date_list:
            if date == f"{str(self.start_year)}.{str(self.start_month).zfill(2)}":
                result.append(balance)
                continue
            current_year = date.split(".")[0]
            if current_year != prev_year:
                self.__increase_monthly_contribution(2.5)
                prev_year = current_year
            monthly_contribution = self.monthly_contribution
            Ror = dict_ROR.get(date).get("Ror")
            total_ROR_lst.append(Ror)
            balance = (1 + Ror) * balance + monthly_contribution
            result.append(balance)
        self.total_ROR_lst = total_ROR_lst
        return result



    @property
    def start_year(self):
        return self.__start_year
    
    @property
    def start_month(self):
        return self.__start_month
      
    @property
    def end_year(self):
        return self.__end_year
    
    @property
    def end_month(self):
        return self.__end_month
    
    @property
    def monthly_contribution(self):
        return self.__monthly_contribution
    
    @property
    def date_list(self):
        return self.__date_list
    
    @property
    def list_ROR(self):
        return self.__list_ROR
    
    @property
    def dict_ROR(self):
        return self.__dict_ROR
