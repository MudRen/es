#include <mudlib.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(6);
        set_name( "vagetable merchant","�˷�" );
        add ("id", ({ "merchant"}) );
        set_short( "vagetable merchant","�˷�");
        set("unit","λ");
        set_long(@ANGEL
����һ�����߲˵�С��
ANGEL
        );
        
        set ("gender", "male");
        set("wealth/gold",7);
        set ("race", "human");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
}