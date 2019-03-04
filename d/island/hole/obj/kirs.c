#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Mahogany Kirs","��ľ�̵�" );
	add( "id",({ "kirs" }) );
	set_short( "��ľ�̵�" );
	set_long(@LONG
	����һ������ľ���ɵĽ�������ն����ħ�Ĺ��á������
	����˭��аħ��ֻҪ����̵���(throw)�����Ϳ����ˡ�
LONG
		);
	set( "unit","��" );
	set( "weight",50 );
	setup_weapon( "dagger",15,10,18 );
	set( "value",({ 10,"gold" }) );
	set( "no_sale",1 );
}

void init(){ add_action( "to_throw","throw" ); }

int to_throw(string arg)
{
	object holder,env,victim;
	string weapon,target,me;
	
	holder=this_player();
	env=environment(holder);
	
	if( !arg || sscanf(arg,"%s to %s",weapon,target)!=2 )
		return notify_fail( "Usage: throw <item> to <target>\n" );
	if( weapon!="kirs" )
		return notify_fail( "��ȷ��Ҫ��������������ȥ��\n" );
	if( target!="vampire" )
		return notify_fail( "��ͻȻ�����������º�ȱ�£������²����֡�\n" );
	if( !(victim=present("kill_vampire1",env)) )
		return notify_fail( "���ﲢû����Ѫ�����Ĵ����Ұ�!\n" );
	if( undefinedp(this_object()->query("charge")) ){
	tell_object( holder,"�㽫�̵�������Ѫ�����Ǻܿ�ϧ��û���С�\n" );
	this_object()->remove();	
	return 1;
	}
	if( victim->query("hurt") )
		return notify_fail( "һ���ʺ�Ķ̵��Ѿ�������Ѫ�������ˣ�û��Ҫ��ڶ��ѡ�\n" );
	me=holder->query( "c_name" );
	tell_object( holder,set_color(
	"\n�����е���ľ������һ���������Ѫ�����ȥ��������Ѫ������ࡣ\n\n","HIR") );
	tell_room( env,set_color(
	"\n"+me+"���е���ľ������һ���������Ѫ�����ȥ��������Ѫ������ࡣ\n\n","HIR"),holder );
	victim->receive_damage( 3000 );
	victim->set( "conditions/bleeding",({ 2,10,500 }) );
	victim->set( "hurt",1 );
	tell_room( env,"\n��Ѫ��ʹ���������˵���벻���������ֱ��ӵ��ֶζԸ��ң�\n\n" );
	this_object()->remove();
	return 1;
}
