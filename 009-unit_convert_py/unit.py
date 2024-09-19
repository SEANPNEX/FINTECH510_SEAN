from typing import Union
CONVERT_DICT={
    "Kilogram": 1.0,
    "Pound": 0.453592,
    "Stone": 6.35029,
    "Jin": 0.5,
    "Seer": 1.25,
    "Gram": 0.001,
    "Oka": 1.2829
}
def convert_mass(value: Union[float, int], origin_unit, result_unit):
    '''
    The function uses a dictionary to convert the input value from origin unit to desired unit
    (value: in, origin_unit: str, result_unit: str) -> result: int
    '''
    convert_param = CONVERT_DICT.get(origin_unit) / CONVERT_DICT.get(result_unit)
    result = float(value * convert_param)
    return result