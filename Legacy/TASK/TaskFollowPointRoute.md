# _TASK_FOLLOW_POINT_ROUTE

--- ns: TASK --- ## TASK_FOLLOW_POINT_ROUTE  // 0x595583281858626E 0xB837C816 void TASK_FOLLOW_POINT_ROUTE(Ped ped, float speed, int routeMode);  Makes the ped go on a point route.  enum eFollowPointRouteMode { TICKET_SINGLE = 0, TICKET_RETURN = 1, TICKET_SEASON = 2, TICKET_LOOP = 3 }  This native is often times used with [`TASK_FLUSH_ROUTE`](#_0x841142A1376E9006) and [`TASK_EXTEND_ROUTE`](#_0x1E7889778264843A)   ## Parameters * **ped**: The ped to give the task to. * **speed**: The speed to move at in m/s. * **routeMode**: The route mode to use, refer to `eFollowPointRouteMode`  ## Examples TaskFlushRoute() TaskExtendRoute(0.0, 0.0, 70.0) TaskExtendRoute(10.0, 0.0, 70.0) TaskExtendRoute(10.0, 10.0, 70.0) TaskFollowPointRoute(PlayerPedId(), 1.0, 0)

### Parameters
* Ped ped
* float speed
* int mode

### Return Value
* void

### Notes
* AP Hash: 0x0xB837C816
* Build: 323
* MulleKD19: Makes the ped go on the created point route.

ped: The ped to give the task to.
speed: The speed to move at in m/s.
int: Unknown. Can be 0, 1, 2 or 3.

Example:
TASK_FLUSH_ROUTE();
TASK_EXTEND_ROUTE(0f, 0f, 70f);
TASK_EXTEND_ROUTE(10f, 0f, 70f);
TASK_EXTEND_ROUTE(10f, 10f, 70f);
TASK_FOLLOW_POINT_ROUTE(GET_PLAYER_PED(), 1f, 0);

