#include <mudlib.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(6);
        set_name( "fish merchant","�㷷" );
        add ("id", ({ "merchant"}) );
        set_short( "fish merchant","�㷷");
        set("unit","λ");
        set_long(@ANGEL
����һ�������С��
ANGEL
        );
        
        set ("gender", "male");
        set("wealth/gold",7);
        set ("race", "human");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
}