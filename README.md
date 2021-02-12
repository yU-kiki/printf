# ft_printf

A recreation of the standard C library's printf function

## Function prototypes:

```
int   ft_printf(const char *fmt, ...)
```
## Usage:

#### Syntax for format specifies:
`%[flags][field width].[precision][length modifier][conversion specifier]`

This implementation of printf supports the following:

<table>
<tr>
<td>
 
| Flags field            |
| ---------------------- |
| `#` &ensp; (hash)      |
| `0` &ensp; (zero)      |
| ` ` ` ` &ensp; (space) |
| `+` &ensp; (plus)      |
| `-` &ensp; (minus)     |


</td>

| TH1 | TH2 |
----|---- 
| TD1 | TD3 |
| TD2 | TD4 |

<td>
| TH1 | TH2 |
----|---- 
| TD1 | TD3 |
| TD2 | TD4 |
</td>
<td>
|flags|
--------
|`0`|
|`-`|
</td>
    <td>
      |field width|
      |--------|
      |`<number>`|
      |`*`|
    </td>
    <td>
      |precision|
      |--------|
      |`<number>`|
      |`*`| 
    </td>
    <td>  
      |length modifier|
      |--------|
    </td>
    <td>
      |conversion specifier|
      |--------|
      |`%`|
      |`c`|
      |`s`|
      |`p`|
      |`d`|
      |`i`|
      |`u`|
      |`x`|
      |`X`|
    </td>
  </tr>
</table>
