#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(16);
	set_name( "Sawyer","��ľ����" );
	add("id",({ "lizardman","sawyer" }) );
	set_short( "��ľ����" );
	set_long(@LONG
�㿴������һλ���׳˶�������ˣ������������Ϲ�
��Ψһ��ͽ�ܣ�����׼��ȥ��Щľ�������Ҿߡ�
LONG
		);
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",400 );
	set( "max_hp",550 );
	set( "hit_points",550 );
	set( "wealth/silver",150 );
	set( "special_defense",([ "none": 25,"all": 22 ]) );
	set( "aim_difficulty",(["critical":30,"vascular":80]) );
	set_perm_stat( "str",20 );
	set_perm_stat( "dex",20 );
	set_natural_armor( 70,34 );
	set_natural_weapon( 65,25,45 );
	set_natural_weapon2( 60,15,35 );
	set_skill( "parry",90 );
	set_skill( "unarmed",100 );
	set_skill( "dodge",80 );
	set( "inquiry",([
			"mahogany" : "@@ask_mahogany",
			"tool" : "@@ask_tool"
			]) );
}

/*
void init()
{
	::init();
	add_action( "k_me","kill" );
}

*/
/*int k_me(string str)
{
	object me;*/
	
	

void ask_mahogany()
{
      if( this_player()->query_temp("lizard_quest/feller") ){
	write(@ALONG
��ľ����˵:
ม���������ľ����ֻҪȥ�һ��־������������һ��ֺ�
����ÿ��ȥ����ֵ��һ��ֶ�����·����������ô���
��ͼ�͹��ߵ�����һ�䣬�����Ҳ�������ľ�ġ�
ALONG
		);
        this_player()->delete_temp("lizard_quest/feller");
        this_player()->set_temp("lizard_quest/tool",1);
        return;
      }
     write("��ľ����˵:������û������·���Ҹ���ȥ�����أ�\n");
     return; 
}

void ask_tool()
{
	object obj;
	if( this_player()->query_temp("lizard_quest/tool") ){
  	write(@BLONG
��ľ���˺ܾ��ȵ�˵:	
�찡!!��û�����߻���ȥ����ľ��������ҲҪ����Ѿ���
���������ˣ���ȥ����ʦ��������һ�Ѿ���(saw) ��ӦӦ
���ɡ�
BLONG
		);
       	this_player()->delete_temp("lizard_quest/tool");
        this_player()->set_temp("lizard_quest/o_feller",1);
        return;
        }
        write("��ľ����˵:������û������·���Ҹ���ȥ�����أ�\n");
        return;
}
