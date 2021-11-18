#ifndef __CELLULAR_SIM70XX_H__
#define __CELLULAR_SIM70XX_H__

/* AT Command timeout for PDN activation */
#define PDN_ACTIVATION_PACKET_REQ_TIMEOUT_MS       ( 150000UL )

/* AT Command timeout for PDN deactivation. */
#define PDN_DEACTIVATION_PACKET_REQ_TIMEOUT_MS     ( 40000UL )

/* AT Command timeout for Socket connection */
#define SOCKET_CONNECT_PACKET_REQ_TIMEOUT_MS       ( 150000UL )

#define PACKET_REQ_TIMEOUT_MS                      ( 5000UL )

/* AT Command timeout for Socket disconnection */
#define SOCKET_DISCONNECT_PACKET_REQ_TIMEOUT_MS    ( 12000UL )

#define DATA_SEND_TIMEOUT_MS                       ( 50000UL )
#define DATA_READ_TIMEOUT_MS                       ( 50000UL )

#define CELLULAR_PDP_INDEX_MAX                     ( 4U )

/* Fixme : This information should be obtained from modem. */
#define CELLULAR_PDN_CONTEXT_TYPE                  CELLULAR_PDN_CONTEXT_IPV4

#ifndef UNREFERENCED_PARAMETER
    #define UNREFERENCED_PARAMETER( x )    ( void ) x
#endif

/*-----------------------------------------------------------*/

/**
 * @brief DNS query result.
 */
typedef enum cellularDnsQueryResult
{
    CELLULAR_DNS_QUERY_SUCCESS,
    CELLULAR_DNS_QUERY_FAILED,
    CELLULAR_DNS_QUERY_MAX,
    CELLULAR_DNS_QUERY_UNKNOWN
} cellularDnsQueryResult_t;

typedef struct cellularModuleContext cellularModuleContext_t;

/**
 * @brief DNS query URC callback fucntion.
 */
typedef void ( * CellularDnsResultEventCallback_t )( cellularModuleContext_t * pModuleContext,
                                                     char * pDnsResult,
                                                     char * pDnsUsrData );

typedef enum cellularCnactState
{
    CNACT_STATE_IDLE,
    CNACT_STATE_CONNECT,
    CNACT_STATE_DISCONNECT,
    CNACT_STATE_UNKNOWN,

    CNACT_EVENT_BIT_ACT = ( 1 << 0 ),
    CNACT_EVENT_BIT_IND = ( 1 << 1 ),
} cellularCnactState_t;

typedef struct cellularModuleContext
{
    /* DNS related variables. */
    PlatformMutex_t dnsQueryMutex; /* DNS query mutex to protect the following data.   */
    QueueHandle_t pktDnsQueue;     /* DNS queue to receive the DNS query result.       */
    uint8_t dnsResultNumber;       /* DNS query result number.                 */
    uint8_t dnsIndex;              /* DNS query current index.                 */
    char * pDnsUsrData;            /* DNS user data to store the result.       */

    CellularDnsResultEventCallback_t dnsEventCallback;

    CellularPdnConfig_t pdnCfg;  /* save PDN/APN setting                     */
    EventGroupHandle_t pdnEvent; /* for AT+CNACT wait +APP PDP: response     */
} cellularModuleContext_t;

/*-----------------------------------------------------------*/

extern CellularAtParseTokenMap_t CellularUrcHandlerTable[];
extern uint32_t CellularUrcHandlerTableSize;

extern const char * CellularSrcTokenErrorTable[];
extern uint32_t CellularSrcTokenErrorTableSize;

extern const char * CellularSrcTokenSuccessTable[];
extern uint32_t CellularSrcTokenSuccessTableSize;

extern const char * CellularUrcTokenWoPrefixTable[];
extern uint32_t CellularUrcTokenWoPrefixTableSize;

/*-----------------------------------------------------------*/

BOOL IsValidCID( int cid );
BOOL IsValidPDP( int pdp );

CellularPktStatus_t _Cellular_ParseSimstat( char * pInputStr,
                                            CellularSimCardStatus_t * pSimState );

/*-----------------------------------------------------------*/

#endif /* ifndef __CELLULAR_SIM70XX_H__ */
