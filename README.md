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
