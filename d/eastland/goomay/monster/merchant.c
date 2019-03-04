#include <../goomay.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "merchant", "�㷷" );
	set_short( "�㷷" );
	set_long(
		"����һ��ʮ�־�׳��ʵ���㷷������ߺ�������������\n"
	);
	set( "race", "orc" );
	set( "gender", "male" );
	set( "alignment", 200 );
	set_skill( "dodge", 60 );
	set( "wealth/gold", 15 );
        set_natural_armor( 40, 20 );
        set_natural_weapon( -16, -5, -5);
        set_perm_stat( "str", 14 );
        set_perm_stat( "int", 12 );
        set_perm_stat( "dex", 14 );
        set_skill( "polearm", 70 );
        set_skill( "parry", 80 );
        set( "hit_points", 300 );
        set( "max_hp", 300 );
        wield_weapon( Obj"balance" );
        equip_armor( Obj"pearl_ring" );

        set( "inquiry", ([
                "hunter" : 
@WINE
���˸��Ҳ��찡������ֻ�ǵ�ͷ֮������������������
����˶��ѣ����������Ķ�����������Ӱ����Ҳ�����ĵģ���֪��
���ǲ��ǳ���ʲ�������ˣ������ȥ����������ס�ھɳǣ����߾�
���ˡ�
WINE
]));

}

