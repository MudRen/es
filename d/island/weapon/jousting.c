/*
 * ԭ���ߣ�Ishige (1995.1)
 * �޸��ߣ�Ishige (1995.12)
 */

#include <mudlib.h>

inherit WEAPON;

string C_NAME=("[36;1m��[0;36m��[36;1m��[0;36m@[36;1m��[0;36m��[36;1m��[0;36mu[37m");
void create()
{
	set_name( "Ultima Trident",C_NAME );
	add( "id",({ "jousting","trident" }) );
	set_short( C_NAME );
	set_long(@LONG
	���ǰ����亱�������������ӵ����������
	���������ʿ��������Ը����ֻ��ϧ�Ѿ���
	֪���ж�����Ϊ��������������ɥʧ�����
	������
LONG
		);
	set( "unit","��" );
	set( "type","jousting" );
	set( "weapon_class",45 );
        set( "min_damage",25 );
        set( "max_damage",52 );
	set( "weight",200 );
	set( "value",({ 5600,"silver" }) );
	set( "nosecond",1 );
	set( "prevent_insert",1 );
	set( "hit_func","hit_fun" );
}

string ex_look(){
return (set_color("$N","HIY")+"���ϵ�"+C_NAME+"�й�[31;5m����ٵ�[37;0m�����ƣ�\n$N����������"+set_color("������","HIB")+"һ�㡣\n" );
}

void wi_fun()
{
	set("extra_look","@@ex_look");
	return;
}

void unwi_fun()
{
	delete( "extra_look");
	return;
}

int hit_fun(object victim,int dis)
{
	object holder;
	int dam,skill,point;
	string name1,name2;
	
	if( !victim ) return 0;
	if( !(holder=environment( this_object() )) || !living(holder) ) return 0;
	if( !(holder->query("justice")) ) return 0;
	point = (int)holder->query("justice");
//	if( point < random (2000) ) return 0;
	if( point <= 1000 ){ dam=5; }
	else if( point > 1000 && point <= 3000 ){ dam=10; }
	else if( point > 3000 && point <= 8000 ){ dam=20; }
	else if( point > 8000 && point <= 17000 ){ dam=30; }
	else if( point > 17000 && point <= 60000 ){ dam=40; }
	else if( point > 60000 ){ 50; }
	
	skill=(int)holder->query_skill("jousting");
	name1=holder->query("c_name");
	name2=victim->query("c_name");
	
	if( random(100) > (15+(skill-100)) ) return 0;
	
	tell_room(environment(victim),"\n"+C_NAME+"��"+set_color("��ʥ����","HIW")+"��������"+name1+"����������"+name2+"�����[34;1;5m�����Թ��ơ�[37;0m���˺���\n\n",holder);
	tell_object(holder,"\n"+set_color("��ʥ������","HIW")+"����������������㷢����"+set_color("����������","HIC")+"��һ����\n\n" );
	holder->add("justice",-4);
	victim->receive_special_damage( "divine", dam );
	victim->set("last_attacker",holder);
	return dam;
}
