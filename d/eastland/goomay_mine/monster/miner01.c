#include <mudlib.h>

inherit MONSTER;

void create()
{

	::create();
	set_level(11);
	set_name( "old miner", "�Ͽ�" );
	add( "id", ({ "miner" }) );
	set_short( "�Ͽ�" );
	set_long(@LONG
������˴�����ʱ���ڶμҹ����ˣ�����֮��μҹ�����������һЩ���ϵ�����
���������������һЩ�ڿ������˺��£�
LONG
);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "int", 15 );

	set( "natural_armor_class", 65 );
	set( "natural_defense_bonus", 20 );
	set_natural_weapon( 23, 18, 26);
	set( "time_to_heal", 2 );
	set( "max_hp", 400 );
	set( "hit_points", 400 );
	set( "gender", "male" );
	set( "alignment", 800 );
	set( "wealth/silver", 200 );
        set( "inquiry",([
             "detonation" : "�Ҳ�������������������Щ����������ʣ�\n",
             "troll" : "��ֻ֪����������������ħ��������(magic magnetite)�ģ�\n",
             "ghost":
"�Ҿ��ǲ�֪��������ְ������˿����������е㲻̫����\n"
"����ָ����һ����·�ɣ��ʿ����Ͼƹ�֪��֪����\n"
]));
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"�Ͽ��������: �������ϱ߳���һЩ�������������!��֪���ǲ����й�(ghost)?\n",
		"�Ͽ�˵��: �Դ���һ��󳡷�����ը(detonation)��,һЩ�˶���ùֵֹģ�\n",
	}));
	}