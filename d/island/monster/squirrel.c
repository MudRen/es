#include "../island.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(2);
        set_name( "squirrel", "����" );
        add( "id", ({ "squirrel" }) );
        set_short( "����" );
        set_long(@LONG
�㿴��һֻ��������β�ͣ������۾���С������֦ͷ��������ȥ��
LONG
);
        set( "unit", "ֻ" );
        set_perm_stat("kar", 3 );
        set_perm_stat("dex", 5 );
        set_natural_weapon(4,2,3);
        set_natural_armor(7,0);
        set_c_verbs( ({ "%s��צ����%sץȥ" }) );
        set_c_limbs( ({ "ͷ��", "����", "�Ȳ�", "β��" }) );
}
