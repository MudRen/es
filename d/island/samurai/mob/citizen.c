#include <mudlib.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(6);
        set_name( "citizen","����" );
        add ("id", ({ "citizen"}) );
        set_short( "citizen","����");
        set("unit","λ");
        set_long(@ANGEL
����һ����ͨ�����񣬵����������һ����ս�����µĳ����У�Ҳ
����һ�����ӵ���
ANGEL
        );
        
        set ("gender", "male");
        set("wealth/silver",70);
        set ("race", "human");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
}