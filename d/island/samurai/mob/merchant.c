
#include <mudlib.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(6);
        set_name( "merchant","�ӻ�����" );
        add ("id", ({ "merchant"}) );
        set_short( "merchant","�ӻ�����");
        set("unit","λ");
        set_long(@ANGEL
����һ���ӻ�������
ANGEL
        );
        
        set ("gender", "male");
        set("wealth/gold",7);
        set ("race", "human");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
}