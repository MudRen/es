#include "../forest.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(5);
        set_name("goblin", "С���");
        add( "id", ({ "goblin" }) );
        set_short("С���");
        set_long(@LONG
����һ�ְ�С, ���ۼ��, �е����ƺ��ӵ����������Ȼ, ���ǱȺ��Ӵ���
���ˡ����Ǵ����ǿ���ʹ�������������, �Գ���é®��ð���߶��������൱Σ��
�ĵ��ˡ�
LONG
        );
        set( "unit", "ֻ" );
        set( "gender", "male" );
        set_natural_armor( 25, 10 );
        set_natural_weapon( 8, 3, 5 );
        set( "alignment", -100 );
        wield_weapon(OBJ"small_dagger");
}

void die()
{
		if( random(10) == 1 ) set("wealth/gold", 2);
		else set("wealth/silver", random(10));
		::die();
}
