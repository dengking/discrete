```python
import re
StockRegex = re.compile('^([\w]*)(\d{6})?$')
m = StockRegex.match(stock_info_str)
name = m.groups()[0]
code = m.groups()[1]
```