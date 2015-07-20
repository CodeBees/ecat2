#ifndef DRVETHERCAT_H
#define DRVETHERCAT_H


#define MAXSTR	(256+1)


/*----------------------------------------*/
/*                                        */
/* drvethercat                            */
/*                                        */
/*----------------------------------------*/



typedef struct {
	int dnr;
	char *rmem;
	char *wmem;

	int dreg_nr;
	domain_register *dreg_info;

} ioctl_trans;



//------------------------------------------------------
#define EC_MAX_NUM_DEVICES 1
#define EC_DATAGRAM_NAME_SIZE 20
/** Size of the EtherCAT address field. */
#define EC_ADDR_LEN 4
#define EC_MAX_DOMAINS	10

//------------------------------------------------------

void process_hooks( initHookState state );


ethcat *ethercatOpen( int domain_nr );

int drvGetRegisterDesc( ethcat *e, domain_register *dreg, int regnr, ecnode **pentry, int *token_num );
int drvGetLocalRegisterDesc( ethcat *e, domain_register *dreg, int *dreg_nr, ecnode **pentry, int *token_num );
int drvGetEntryDesc( ethcat *e, domain_register *dreg, int *dreg_nr, ecnode **pentry, int *token_num );
int drvDomainExists( int mnr, int dnr );

int drvGetValue( ethcat *e, int offs, int bit, epicsUInt32 *rval, int bitlen, int bitspec, int wrval, int byteoffs, int bytelen );
int drvSetValue( ethcat *e, int offs, int bit, epicsUInt32 *rval, int bitlen, int bitspec, int byteoffs, int bytelen );

int drvGetValueMasked( ethcat *e, int offs, int bit, epicsUInt32 *val, int bitlen, epicsInt16 nobt, epicsUInt16 shift, epicsUInt32 mask, int byteoffs, int bytelen );
int drvSetValueMasked( ethcat *e, int offs, int bit, epicsUInt32 *val, int bitlen, epicsInt16 nobt, epicsUInt16 shift, epicsUInt32 mask, int byteoffs, int bytelen );

int drvGetValueString( ethcat *e, int offs, int bitlen, char *val, char *oval, int byteoffs, int bytelen );
int drvSetValueString( ethcat *e, int offs, int bitlen, char *val, char *oval, int byteoffs, int bytelen );

int drvGetValueFloat(
		ethcat *e,
		int offs,
		int bit,
		epicsUInt32 *val,
		int bitlen,
		int bitspec,
		int wrval,
		int byteoffs,
		int bytelen,
		epicsType etype,
		double *fval
 );
int drvSetValueFloat(
		ethcat *e,
		int offs,
		int bit,
		epicsUInt32 *val,
		int bitlen,
		int bitspec,
		int byteoffs,
		int bytelen,
		epicsType etype,
		double *fval
 );

int parse_datatype_get_len( epicsType etype );

extern int wt_counter[EC_MAX_DOMAINS];
extern int delayed[EC_MAX_DOMAINS];
extern int recd[EC_MAX_DOMAINS];
extern int forwarded[EC_MAX_DOMAINS];


#endif


















