#include <../goomay.h>

inherit OBJECT;

void create()
{
	seteuid( getuid() );
	set_name( "royal mark", "���ͽ���" );
	add( "id", ({ "mark" }) );
	set_short( "���ͽ���" );
	set_long(
		"����һ�����ͽ��ƣ�����������������൱춵�����ϵ�Ȩ������Ҫʱ��\n"
		 "���԰�����(show)���������� !\n"
	);
	set( "unit", "��" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
        add_action( "show_me", "show");
}

int show_me(string arg)
{
	string who,item;
	object target,ob;

        if( !arg || arg=="" || sscanf( arg, "%s to %s", item,who)!=2 )
                return notify_fail("��Ҫ��(show)ʲ���(to)˭������\n");

	if (item != "mark")
                return notify_fail("�ⶫ����ʲ����ֵģ����� !!\n");

	if (!target=present(who,environment(this_player()))) 
		return notify_fail("����û������� !!\n" );
	
	if ( (string)target->query("name") == "Hsin the scribe" ) 
	{
		if ( !target->query("show") ) {
                tell_object( this_player(), @SHOW
��ʦү�е�����ԭ�����ղ�󳼼ݵ���С�����ȥ֪ͨʷ���˳���ӭ�ӡ�
������Ժ� !! ���˰� ... ������ˡ�������ææ�����˴�Ѷ��


���ã�����ת��һ�����ٷ����ˣ����㳤Ҿ��������÷����ʷҫǰ��ӭ
�ղ���ˣ���֪���������кμ��̡�
SHOW
		);
		new(Mob"migastrate" )->move(environment(environment()) );
			  target->set("show",1);
			  return 1;
			  }
		
	}
        else if ( (string)target->query("name") == "Captain of Policeman")
        {
		if ( !target->query("show")) {
                tell_object(this_player(), 
                "�β�ͷ�е�����ԭ�����ղ�󳼼ݵ�������Ҫ����𣿰� ... ��� ...��\n"
		"����Ǽ��ε�Կ�ף��������ȥ֮ǰ��ؼǵý����¹� !! ����\n"
		"�η�ӥ����һ����Կ�ס�\n");

		ob=new( Obj"key1" );
		ob->move( environment(this_object()) );
		target->set("show",1);
		return 1;
		}
	}
		tell_object( target ,this_player()->query("c_name")+"�ó�һ�鶫��������ǰ�һΡ�\n");
                tell_object( this_player(), 
                target->query("c_name")+"�������ô�һ����Ӱ� !! ֵ����Ǯ� !! ��\n");
                return 1;
}
