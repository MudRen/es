#include <mudlib.h>
inherit OBJECT;
 
void create()
{
        set_name( "break jade", "������" );
        add( "id", ({ "jade" }) );
        set_short( "������" );
        set_long( @C_LONG
����һ���ϺõĴ��񣬲����ƺ�������������һ���顣������׭�ֿ���һ�����⡻�֡�
C_LONG
                );
        set("unit","��");
        set("weight", 10);
        set("sky_guilt_jade1",1);
        set("value",({10, "silver"}) );
        set("no_sale", 1 );
}
