/**
 * @param {string} IP
 * @return {string}
 */
var validIPAddress = function (IP) {
  const parts = IP.split(".");

  if (parts.length === 4) {
    for (const part of parts) {
      if (
        !part ||
        part.length > 3 ||
        Number(part) != part ||
        Number(part) > 255
      ) {
        return "Neither";
      }
    }

    return "IPv4";
  } else {
    const parts = IP.split(":");

    if (parts.length === 8) {
      for (const part of parts) {
        if (!part || part.length > 4 || isNaN(Number("0x" + part))) {
          return "Neither";
        }
      }

      return "IPv6";
    }
  }

  return "Neither";
};

console.log(validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334"));
