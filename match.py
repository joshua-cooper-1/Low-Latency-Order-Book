'''
Fundamental idea of a MatchingEngine,
written in inefficient Python code.
'''


class MatchingEngine:
    def __init__(self):
        self.buys = []
        self.sells = []

    def __init__(self, buys, sells):
        self.buys = buys
        self.sells = sells
    
    def add_buy(self, buy):
        self.buys.append(buy)
        self.buys.sort(reverse=True)

    def add_sell(self, sell):
        self.sells.append(sell)
        self.sells.sort()

    def match(self):
        while self.buys and self.sells:
            sell = self.sells.peek()
            buy = self.buys.peek()

            if sell <= buy:
                self.execute_trade(buy, sell)

            else:
                break

    def execute_trade(self, buy, sell):

        sell = self.sells.pop(0)
        buy = self.buys.pop(0)


    




