from salaried_employee import SalariedEmployee


class CommissionedEmployee(SalariedEmployee):
    def __init__(self, name, job_title, annual_pay_rate, period_gross_sales):
        super().__init__(name, job_title, annual_pay_rate)
        self.__period_gross_sales = period_gross_sales

    @property
    def employee_type(self):
        return "commissioned"
    
    @property
    def period_gross_sales(self):
        return self.__period_gross_sales
    
    @period_gross_sales.setter
    def period_gross_sales(self, new_sales):
        self.__period_gross_sales = new_sales

    def calculate_pay(self):
        return super().calculate_pay() + (self.period_gross_sales * 0.05)