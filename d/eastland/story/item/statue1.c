#include <mudlib.h>
inherit OBJECT;

void create()
{
        set_name("stone statue","石雕像");
        add( "id" , ({ "statue" }) );
        set_short( "石雕像");
        set_long(@C_LONG
一座栩栩如生的十尺长雕像；上像刻划的是个神态威武的战士，它正在跟一只野兽
搏斗。你不禁地想向它膜拜(worship)，景仰之心油然而生。
C_LONG  );      
        set("unit","座");
        set("prevent_get",1);
}
