from equity import Equity
from bond import Bond


class Lifecycle():
    """Life cycle calculator"""

    def __init__(self, equity_filename, bond_filename, start, end, monthly_contribution) -> None:
        self.__equity_part = Equity(equity_filename, start, end, monthly_contribution)
        self.start = start
        self.__bond_part = Bond(bond_filename, start, end, monthly_contribution)
        self.__monthly_contribution = monthly_contribution
        self.__proportion = 1

    def __update_proportion(self):
        self.__proportion -= 0.02
        self.__proportion = round(self.__proportion, 2)
        if self.__proportion <= 0:
            self.__proportion = 0

    def __increase_monthly_contribution(self, rate):
        self.__monthly_contribution *= (1 + (rate / 100))

    def calculate_plan(self):
        balance = 100
        result = []
        date_list = self.equity_part.date_list
        prev_year = date_list[0].split(".")[0]
        dict_equity_ROR = self.equity_part.dict_ROR
        dict_bond_ROR = self.bond_part.dict_ROR
        for date in date_list:
            if date == self.start:
                result.append(balance)
                continue
            current_year = date.split(".")[0]
            if current_year != prev_year:
                self.__update_proportion()
                self.__increase_monthly_contribution(2.5)
                prev_year = current_year
            monthly_contribution = self.monthly_contribution
            Index_ROR = dict_equity_ROR.get(date).get("IndexROR")
            Div_ROR = dict_equity_ROR.get(date).get("Div")
            Bond_ROR = dict_bond_ROR.get(date).get("Ror")
            total_equity_ROR = Index_ROR + Div_ROR 
            balance = (self.__proportion * balance) * (1 + total_equity_ROR) \
                        + ((1 - self.__proportion) * balance) * (1 + Bond_ROR) \
                        + monthly_contribution
            result.append(balance)
        return result

    @property
    def monthly_contribution(self):
        return self.__monthly_contribution

    @property
    def equity_part(self):
        return self.__equity_part
    
    @property
    def bond_part(self):
        return self.__bond_part