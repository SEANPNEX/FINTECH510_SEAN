import unittest
from credit_card import validate


class TestCreditCardValidator(unittest.TestCase):
    """
    Tests a credit card number validator
    """

    def test_valid_visa(self):
        """Ensures a valid visa number passes"""
        self.assertTrue(validate("4263982640269299"))

    def test_valid_mastercard(self):
        """Ensures a valid mastercard number passes"""
        self.assertTrue(validate("5425233430109903"))        

    def test_valid_american_express(self):
        """Ensures a valid american express number passes"""
        self.assertTrue(validate("374245455400126")) 

    def test_invalid_american_express(self):
        """Ensure an invalid american express number fails"""
        self.assertFalse(validate("377024907644532"))                   

    def test_invalid_card(self):
        """Unsupported type of card should fail"""
        self.assertFalse(validate("1225233430109903"))    

    # my cases
    # len boundary test
    def test_visa_len_boundary_1(self):
        """Boundary test 1: 15 digit visa"""
        print(f"len of the visa: {'426398264026929'.__len__()}")
        self.assertFalse(validate("426398264026929"))   

    def test_visa_len_boundary_2(self):
        """Boundary test 2: 17 digit visa"""
        print(f"len of the visa: {'42639826402692999'.__len__()}")
        self.assertFalse(validate("42639826402692999")) 
    
    def test_Master_len_boundary_1(self):
        """Boundary test 2: 15 digit master"""
        print(f"len of the master: {'542523343010990'.__len__()}")
        self.assertFalse(validate("542523343010990"))

    def test_Master_len_boundary_2(self):
        """Boundary test 2: 17 digit master"""
        print(f"len of the master: {'54252334301099000'.__len__()}")
        self.assertFalse(validate("54252334301099000"))

    def test_AE_len_boundary_1(self):
        """Boundary test 2: 14 digit AE"""
        print(f"len of the AE: {'37424545540012'.__len__()}")
        self.assertFalse(validate("37424545540012"))

    def test_AE_len_boundary_2(self):
        """Boundary test 2: 16 digit AE"""
        print(f"len of the AE: {'3742454554001260'.__len__()}")
        self.assertFalse(validate("3742454554001260"))

    # prefix boundary test
    def test_visa_pre_1(self):
        """visa boundary"""
        self.assertTrue(validate("4063982640269299"))

    def test_visa_pre_2(self):
        """visa boundary"""
        self.assertFalse(validate("3963982640269299"))

    def test_visa_pre_3(self):
        """visa boundary"""
        self.assertFalse(validate("4963982640269299"))

    def test_visa_pre_4(self):
        """visa boundary"""
        self.assertFalse(validate("5063982640269299"))

    def test_master_pre_1(self):
        """master boundary"""
        self.assertTrue(validate("5163982640269299"))

    def test_master_pre_2(self):
        """master boundary"""
        self.assertTrue(validate("5563982640269299"))

    def test_master_pre_3(self):
        """master boundary"""
        self.assertFalse(validate("5663982640269299"))

    def test_master_pre_4(self):
        """master boundary"""
        self.assertFalse(validate("2220982640269299"))

    def test_master_pre_5(self):
        """master boundary"""
        self.assertFalse(validate("2721982640269299"))

    def test_AE_pre_1(self):
        """AE boundary"""
        self.assertFalse(validate("364245455400126"))

    def test_AE_pre_2(self):
        """AE boundary"""
        self.assertFalse(validate("384245455400126"))

    def test_AE_pre_3(self):
        """AE boundary"""
        self.assertFalse(validate("354245455400126"))

    def test_AE_pre_4(self):
        """AE boundary"""
        self.assertFalse(validate("334245455400126"))


if __name__ == '__main__':
    unittest.main(argv=['unittest', 'TestCreditCardValidator'], verbosity=2, exit=False)