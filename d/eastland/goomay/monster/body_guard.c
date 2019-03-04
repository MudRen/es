
#include "../goomay.h"
#include <stats.h>
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(15);
        set_name( "Bodyguard", "�ĳ�����" );
        add ("id",({ "guard"}));
        set_short( "�ĳ�����");
        set("unit","λ");
        set_long(
@C_LONG
����һ�����ļ�Ϊ���µ�����������������ϸϸ��Ƭ�����Ϸ���������͹⣬
����һ�߰�\��������β��һ�߿�����ע������Ҳ�����³����ԣ�����������
�����ƺ�ûʲ��Ǯ����Ŷ�����˰� !! ��������������������������Ц��
����������� !! �������ư� !��
C_LONG
);
        set ("gender", "male");
        set ("race", "lizardman");
        set_natural_armor( 45, 10 );
        set_natural_weapon( 0, 5, 10 );
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_skill( "axe", 90 );
        set_skill( "two-weapon", 90 );
        set_skill( "parry", 60 );
        set( "hit_points", 600 );
        set( "max_hp", 600 );
        set( "special_defense", ([ "all": 20 ]) );
        wield_weapon( Obj"iron_axe" );
        wield_weapon2( Obj"iron_axe" );
        equip_armor( Obj"steel_tail" );
}

void init()
{
        add_action( "pay_me", "pay");
}

int pay_me(string arg)
{
        string who, type;
        int num;
	object obj;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail(
                        "��˭������Ǯ��\n");
        if( !id(who ) ) return 0;
       if( !this_player()->debit(type, num) ) return notify_fail(
		           "��û�������Ǯ��\n");

         tell_room( environment(), 
          "����������Ц����лл�� !! Ҫ�³����������� \n" ,
          this_object() );
                return 1;

}
