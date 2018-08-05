#ifndef field_h_
#define field_h_

#include <nonlibc.h>
#include <stdint.h>
#include <unistd.h>

/* xdpk_field
 * @offt : positive offset from start of packet, negative from end; in bytes.
 * @mlen : mask length in bits (and implicitly: length of field being masked).
 */
struct xdpk_field {
	int16_t		offt;
	uint16_t	mlen;
}__attribute__((packed));

/*	xdpk_field_len()
 * Use the mask bitcount to extrapolate field length.
 * 0 is a valid length.
 */
NLC_INLINE size_t xdpk_field_len(uint16_t mlen)
{
	/* bitmask -> bytecount */
	size_t len = (mlen >> 3);
	if (mlen & 0x7)
		len++;
	return len;
}

NLC_LOCAL __attribute__((const))
	uint8_t xdpk_field_tailmask(uint16_t mlen);

NLC_PUBLIC __attribute__((pure))
	uint64_t xdpk_field_hash(struct xdpk_field fd, const void *pkt, size_t plen);

#endif /* field_h_ */