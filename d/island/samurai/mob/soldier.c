#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(7);
        set_name("soldier","����ʿ��" );
        add ("id", ({ "soldier","young"}) );
        set_short( "young soidier","����ʿ��");
        set("unit","λ");
        set_long(@ANGEL
����һ����ʿ���е�λ��͵�ʿ�����Ǹ��ոձ�����������±�
ANGEL
        );
        
        set ("gender", "male");
        set("wealth/silver",50);
        set ("race", "human");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        wield_weapon(MOBJ"iron_blade.c");
}