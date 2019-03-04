#include <mudlib.h>
#define ISLAND "/d/island/"
#define IOBJ  "/d/island/obj/"

inherit ISLAND+"magic";
inherit MONSTER;

void create()
{
	object ob1,ob2,ob3,ob4; 

	::create();
	set_level(1);
	set_name("Shopkeeper","Ǯ�ƹ�");
	add("id",({"keeper"}) );
	set_short("Ǯ�ƹ�");
	set_long(@LONG
Ǯ�ƹ���ΪԼĪ��ʮ��ͷ���������ӣ���߹���һ��С���ӣ��������������
��ʮ��ľ�������ģ������������Ƣ���е�Ź֣��⴫�����Ƿ���һʱ�Ĵ��
��������ò�Ҫ�����й�С͵(thief) ������Ŷ���������ŭ������ѽ������
��������һ����Ŷ�����ڶ�ʱ�����������������е��˺�(scar)Ŷ����������
����ס�ģ�һ���޷��ӳ����Ļ��ۣ�
LONG
		);
	set("unit","λ");
	set("gender","male");
	set("alignment",-500);
	set("race","daemon");
	set("no_attack",1);
	set("inquiry",([
			"thief":"@@ask_thief",
			"scar" :"@@ask_scar",
			]) );
/*	set("aiming_loc","critical");
	ob1=new(IOBJ"boots03");
	ob1->move(this_object());
	ob2=new(IOBJ"cloth02");
	ob2->move(this_object());
	ob3=new(IOBJ"armband01");
	ob3->move(this_object());
	ob4=new(IOBJ"dagger01");
	ob4->move(this_object());        
*/
}
void ask_thief()
{
    write("Ǯ�ϰ�˵:�Ҳ��ɴ���Ѿ��ܾ���, �������㣡\n");
    return;
}
    
/*void ask_thief(object victim)
{
	object env;

        if(query_attackers()) return ;
	env = environment(this_object());
	if( victim->query_level() < 8 ) {
		tell_object( victim,"Ǯ�ƹ�������ļ��˵: С����Ҫѧ�ã���ѧ��С͵ม�\n" );
		return 0;
	}
	write( "Ǯ�ƹ���ɫһ����ͻȻ������һ������һ��������ֻ��һ�ź�Ӱ������˹�������\n" );
	tell_room( env,"\nͻȻһ������ֻ��һ����Ӱ��"+victim->query("c_name")+"���˹�ȥ��\n",victim );
	tell_room( env,"Ǯ�δ����ͳ�����ı��ꡣ\n" );
	tell_room( env,"Ǯ�δ��ɴӹ�̨�����ó������������ϡ�\n" );
	set_skill( "dagger",100 );
	command( "wear all",this_object() );
	command( "wield daggercheck",this_object() );
	set_level(18);
	set( "aim_difficulty",([ "weakest":35,"vascular":30,"ganglion":30 ]) );
	set( "stun_difficulty",30 ) ;
	set_perm_stat( "con",20 );
	set_perm_stat( "str",23 );
	set_perm_stat( "dex",22 );
	set_perm_stat( "kar",22 );
	set_perm_stat( "pie",30 );
	set( "max_hp",650 );
	set( "hit_points",650 );
	set_name( "Great Thief","Ǯ�δ���" );
	add("id",({ "thief" }) );
	set_short( "���  Ǯ�δ���" );
	set_long(@LONG
ԭ��Ǯ�ƹ�����Ƿ���һʱ�����ִ������ֻ����ȫ��װ��һ��
�����ܻ���ģ�������ϰ���һ���ֽ�д���ĸ��֡�һ����������
LONG
		);
	set( "no_attack",0 );
	set( "c_killer_msg","\nͻȻһ������ֻ��һ����Ӱ�������˹�����\n" );
	set( "tactic_func","my_tactic" );
	set_skill( "dodge",100 );
	set_skill( "anatomlogy",100 );
	set( "chat_chance",20 );
	set( "att_chat_out",({
	"Ǯ�δ��ɴ��: ��С�ӣ����ҵ������������֪���Ĺ�ȥ���Ҹ�������壡��\n"
			}) );
	set_natural_weapon( 45,25,40 );
	set_natural_armor( 65,30 );
	set( "special_defense",(["mental":90,"cold":80,"evil":70,"fire":65,"none":55,"energy":15])); 
	kill_ob( victim );
	set( "killer",1 );
} 

int my_tactic()
{
	object env,victim;
	string him;
	
	env = environment(this_object());
	if( !(victim=query_attacker()) ) return 0;
	him = victim->query("c_name");
	if( random(20) < 2){
		tell_object(victim,"\nǮ�δ���˳��һ�ӣ���ö�����������˹��������������ס��.......\n"
				   "�ۡ������Ү������������\n\n" );
		tell_room( env,"\nǮ�δ���͵͵����"+him+"�Ű�������֣���"+him+"���򵽾�Ȼ��͵Ц��\n\n",victim );
		victim->add( "wealth/gold",2 );
		return 1;
	}
	
	else if( random(25) < 5){
		tell_object( victim,"\nͻȻ�������ݡ�����������������������������������ϣ��ۣ���ʹ����\n\n" );
		tell_room( env,"\nǮ�δ���˳��һ������������������ȫ����"+him+"���ϣ�\n\n",victim );
		victim->receive_special_damage("evil",30);
		report( victim );
		return 1;
	}
	else return 0;
}

void ask_scar()
{
	int jus;
	
	jus = (int)this_player()->query("justice");
	if( !jus ){
		write( "Ǯ�ƹ�ָ�����Ц������ȫ��ǬǬ������, һ���˺�Ҳû��, �������������?????\n" );
		return ;
	}
	write( "Ǯ�ƹ����ֳ���˵����!!����ȫ�����²�����С�˺�"+jus+"��, ����������Ҳ!!\n" );
	return ;
}
*/