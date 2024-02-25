import pandas as pd
class Preprocessor:
    
    def __init__(self, review_df:pd.DataFrame) -> None:
        self.review_df = review_df

    def clean_data(self):
        self.review_df.drop_duplicates(inplace=True)
        self.review_df.dropna(inplace=True)
