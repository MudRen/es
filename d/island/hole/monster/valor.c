#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "Lizardman Valor","��������ʿ" );
	add( "id",({ "lizardman","valor" }) );
	set_short( "��������ʿ" );
	set_long(@LONG
    �����������������ѡ�����ĵ�һ��ʿ����������Ϊ
�������������������Ʋ��֣�����һ���������ƾơ�
LONG
		);
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",500 );
	set_natural_armor( 90,25 );
	set_natural_weapon( 70,28,60 );
	set_natural_weapon2( 65,24,50 );
	set( "max_hp",800 );
	set( "hit_points",800 );
	set_perm_stat( "str",25 );
	set_perm_stat( "dex",20 );
	set_perm_stat( "kar",25 );
	set_skill( "parry",100 );
	set_skill( "tactic",100 );
	set_skill( "axe",100 );
	set_skill( "dodge",80 );
	set( "tactic","assault" );
	set( "wealth/silver",700 );
	set( "special_defense",([ "all":38,"none":20 ]) );
	set( "aim_difficulty",([
				"weakest":70,"critical":70,
				"vascular":45,"ganglion":80
				]) );
	set( "stun_difficulty",60 );
	set( "inquiry",([ "trouble" : "@@ask_trouble" ]) );
	set( "chat_chance",15 );
	set( "chat_output",({
	"��������ʿ���ǲ����˵������������������\n"
			}) );
}

void init()
{
	::init();
	add_action( "to_help","help" );
}

int to_help(string str)
{
	object player;
	string who;
	int wine;
	
	player=this_player();
	wine=player->query_temp("lizard_quest/valor");
	if( !str || sscanf(str,"%s",who)!=1 || who!="valor" ){
	tell_object( player,"�������˭��\n" );
	return 1;
	}
	if( undefinedp(wine) ){
	tell_object( player,"��������ʿ˵�������£����ҺȾưɡ�\n" );
	return 1;
	}
	if( wine < 7 ){
	tell_object( player,"��������ʿ˵������������!\n" );
	return 1;
	}
	if( wine==7 ){
	tell_object( player,@HELP
��������ʿ�˷ܵ�˵��
���������ң�������������ң������ȥ�Ҳ���ϣ��
���䣬����������Ҫ��ȥ�����ģ����ͻ��������ϸ����
�Ρ�
HELP
		);
	player->set_temp("lizard_quest/leader",1);
	player->set_explore("island#6");
	return 1;
	}
	tell_object( player,"���������Ҳ�в������������Ҳû���Ӱ��ޡ�\n" );
	return 1;
}

int accept_item(object me,object item)
{
	string *name;
	int lv;

	name=item->query("id");
	if( name[0]=="wheet wine" ){
	if( undefinedp( lv=me->query_temp("lizard_quest/valor") ) ){
	tell_object( me,"��������ʿ˵��лл��ľơ�\n" );
	command( "drink wheet wine" );
	return 1;
	}
	else{
	tell_object( me,"��������ʿ˵���š����þƣ���Ǭ������\n" );
	command( "drink wheet wine" );
	lv=me->query_temp( "lizard_quest/valor" );
	me->set_temp( "lizard_quest/valor",lv+1 );
	return 1;
	}
	}
	tell_room( environment(this_object()),
	"��������ʿ�ȵ�������С�����ⶫ����ȥ����������\n" );
	item->remove();
	return 1;
}

void ask_trouble()
{
	object player;
	int wine;
	
	player=this_player();
	wine=player->query_temp("lizard_quest/valor");
	if( undefinedp(wine) ){
	tell_object( player,@ALONG

��������ʿ���������˵��
��Ҫ���ҺȾ��𣿲�����ϧ�����ҵľƶ�������....

ALONG
		);
	player->set_temp("lizard_quest/valor",1);
	return ;
	}
	if( wine > 7 ){
	tell_object( player,"��������ʿ�Ѿ���������ˣ��޷��ش����κ����⡣\n" );
	return ;
	}
	switch( wine ){
	case 2 :
		tell_object( player,@BLONG

��������ʿ�����̾��һ����˵��
��˵��Щ�����£����������ȣ��������ǲ�����.......

BLONG
		);
		player->set_temp("lizard_quest/valor",3);
		return ;
		break;
	case 4 :
	tell_object( player,@CLONG
	
��������ʿ������ץ����˵��
�����������������ġ���������������䶷��Ĺھ���Ҳ
������ν����ʿ���չ������������µ���ʿһ������
������ε�����ȴ�ѵ�����............�㻹�о���

CLONG
		);
		player->set_temp("lizard_quest/valor",5);
		return ;
		break ;
	case 6 :
	tell_object( player,@DLONG

��������ʿ����˵����
������Ǵ����泣����һЩ�ڱ���վ����ʱ��Ī�������
��ɱ��������������Ϊ��������ʿ�������߸ɵĺ��¡���
�ǣ���������ÿ�����߶��Ǳ���Ǭȫ���Ѫ������������
����˵�����Ǵ������й����������Ŀ���߶��Ѿ�����
������������һ��ͷ����û�У���������Ǻ��أ���ϣ��
�����ܰ��ҡ�����������......�Ⱦưɡ�

DLONG
		);
		player->set_temp("lizard_quest/valor",7);
		return ;
		break;
	default :
	tell_room( environment(this_object()),
	"��������ʿ���˿��㣬�ּ����Ⱦơ�\n" );
		return ; 
	}
	return ;
}
