#include <../island.h>

inherit MONSTER;
void create()
{
	::create();
	seteuid(getuid());
	set_level(19);
	set_name( "Lizardman Holy Knight","ʥ��ʿ����" );
	add( "id",({ "lizardman","knight" }) );
	set_short( "ʥ��ʿ����" );
	set_long(@LONG
    ���Ǵ���Ϊ�˼���ʥ��ʿ���ص����˴����һ�����񣬴������
���������ݷ���������ȥ���ġ���Ȼֻ�Ǹ����񣬵����ְ�����Ȼ��
���˸е����¡�
LONG
		);
	set( "exp_reward",50000 );
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",1400 );
	set( "time_to_heal",6 );
	set_natural_armor( 55,10 );
	set_natural_weapon( 90,55,90 );
	set_natural_weapon2( 85,45,80 );
	set( "max_hp",1000 );
	set( "hit_points",1000 );
	set_perm_stat( "str",30 );
	set_perm_stat( "kar",30 );
	set_perm_stat( "dex",30 );
	set_skill( "parry",100 );
	set_skill( "block",100 );
	set_skill( "unarmed",100 );
	set_skill( "two-weapon",100 );
	set_skill( "dodge",100 );
	set_skill( "tactic",100 );
	set( "wealth/gold",1000 );
	set( "tactic","assault" );
	set( "special_defense",
	([ "fire":80,"cold":80,"energy":80,"electric":80,"energy":80,"none":80 ]) );
	set( "aim_difficulty",
	([ "vascular":35,"ganglion":100,"weakest":65,"critical":60 ]) );
	set( "stun_difficulty",75 );
	set( "no_attack",1 );
//	equip_armor( IOBJ"shield01" );
//	equip_armor( IOBJ"boots02" );
//	equip_armor( IOBJ"tail01" );
//	equip_armor( IOBJ"plate02" );
//	equip_armor( IOBJ"ring01" );
//	equip_armor( IOBJ"glove01" );
//	equip_armor( IOBJ"arm01" );
//	equip_armor( IOBJ"necklace01" );
//	equip_armor( IOBJ"helmet01" );
}

int accept_item(object me,object item)
{
	string name,iname;
	object obj;
	
	name=this_player()->query( "c_name" );
	iname=item->query( "c_name" );
	
	if ( iname!="ʥ��ʿԪ��" )
	{
	obj=new( IOBJ"bill" );
	obj->set_long( "\n��л��¡�"+name+"������������"+iname+"��\n\n\n           ��ƽ�����ù��������˾�����֤����\n");  
	obj->move(me);
	item->remove();
	tell_room(environment(),"\n��֪��������Ĺ�����Ա����"+name+"Ц��Ц�����ͳ�һ��ֽ����"+name+"\n",this_player());
	tell_object(this_player(),"\n��ʥ��ʿ�����߳�һ���ˣ����Ի��ɵ������˿��㣬���ͳ�һ��ֽ���㣬���书�����𣡣�\n\n");

	return 1;
	}
	else
	{
	if( (int)this_player()->query_temp("holy_knight")==1){
	this_player()->set_temp("jousting",1);
	}
	tell_room(environment(),"\nͻȻʥ��ʿ�������Ϸ������ɹ�â������Ȼ��������.....\n\n");
	item->remove();
	set_name( "lizardman Holy Knight","������ʥ��ʿ" );
	set_short( "������ʥ��ʿ" );
	set_long(@C_LONG
    ���������ľ��Ǵ�˵�С�������ꪡ������ˡ�ʥ��ʿ����Ҳ���ǵ���������
���еġ�����սʿ������ʱ��������ս��ս����˵��ǰ���ң�����������ֱ��
��ʥ��ʿ�����ֲ���ֹ�˷���������ʿ����ɱ¾����ս�����һ���䣻����ͣ
������ڡ�ӳ���塻ǩ�º�ƽ��Լ��Ȼ��������Ϊ��ʾ��ƽ�ĳ��⣬��ǽ�����
����ꪡ����ڡ�ӳ���塻�Ĺ㳡�ϣ�������ħ���÷�������������ꪡ���ӡס��
�����Ϊ��ӳ���塻�к�ƽ�����硣

C_LONG
		);
	set( "no_attack",0 );
	command("go down");
	return 1;
	}
	return 1;
}

void leave()
{
	command("go up");
	tell_room(environment(),"\nʥ��ʿҡҡͷ��̾�˿����� ͻȻ��һ����â��ʥ��ʿ����������.....\nʥ��ʿ�ֱ�ɽ�����......\n\n");
	set( "no_attack" , 1 );
	set_name( "Lizardman Holy Knight","ʥ��ʿ����" );
	set_short( "ʥ��ʿ����" );
	set_long(@LONG
    ���Ǵ���Ϊ�˼���ʥ��ʿ���ص����˴����һ�����񣬴������
���������ݷ���������ȥ���ġ���Ȼֻ�Ǹ����񣬵����ְ�����Ȼ��
���˸е����¡�
LONG
		);
	return ;
}
