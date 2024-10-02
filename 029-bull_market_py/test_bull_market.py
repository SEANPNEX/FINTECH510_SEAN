import unittest
from bull_market import find_longest_period


class TestBullMarket(unittest.TestCase):
    """
    Tests bull market 
    """
    def test_bull_market_1(self):
        """Test the list contains non-numeric"""
        with self.assertRaises(Exception) as context:
            lst = ["a", 5475.25, 5480.40, 5474.00, 5501.23, 5510.30, 5518.42, 5512.41, 5514.92, 5517.76, 5522.44]
            find_longest_period(lst)
        self.assertTrue(type(context.exception) is TypeError, "Incorrect exception raised")

    def test_bull_market_2(self):
        """test numbers"""
        lst = [5475.25, 5480.40, 5474.00, 5501.23, 5510.30, 5518.42, 5512.41, 5514.92, 5517.76, 5522.44]
        self.assertEqual(find_longest_period(lst), [5474.00, 5501.23, 5510.30, 5518.42], "Incorrect result")

    def test_empty_list(self):
        """test ValueError raised on empty list"""
        self.assertEqual(find_longest_period([]), [], "Incorrect result")


if __name__ == '__main__':
    unittest.main(argv=['unittest', 'TestBullMarket'], verbosity=2, exit=False)