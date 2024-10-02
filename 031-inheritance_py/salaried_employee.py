from employee import Employee


class SalariedEmployee(Employee):
    """Salaried Employee"""

    def __init__(self, name, job_title, annual_pay_rate):
        super().__init__(name, job_title)
        self.__annual_pay_rate = annual_pay_rate
        self.__period_worked = 1

    @property
    def employee_type(self):
        return "salaried"
    
    @property
    def annual_pay_rate(self):
        return self.__annual_pay_rate
    
    @annual_pay_rate.setter
    def annual_pay_rate(self, new_rate):
        self.__annual_pay_rate = new_rate

    @property
    def period_worked(self):
        return self.__period_worked

    @period_worked.setter
    def period_worked(self, period):
        self.__period_worked = period

    def calculate_pay(self):
        period = self.period_worked
        return period * ((1 / 24) * self.annual_pay_rate)