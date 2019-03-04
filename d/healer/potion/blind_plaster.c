#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	set_name("blind plaster", "��Ŀ��" );
	add( "id", ({"plaster"}) );
	set_short("��Ŀ��");
	set_long(
		"��������������΢�۾��˺���ҩ��, ����Ϳ(apply)���۾��Ͽ��Ը���\n"
		"ʧ����״��, ����˵�̫��, ����Ҫ������ҽ�ơ�\n"
	);
	set( "can_apply", 1 );
	set( "unit", "��" );
	set( "weight", 20 );
	set( "value", ({ 100, "silver" }) );
}

int apply(object player)
{
	int degree;
	if( !(degree=player->query("blind")) ) return 0;
	if( degree > 5) {
	  tell_object(player, "�������̫��, ��ҩ�Ѿ�û����, ��ҽ���������ɡ�\n");
	  return 1;
	}  
	degree--;
	if (degree<1) { 
	  player->delete("blind");
	  tell_object(player, "����۾����ܿ��������ˡ�\n");
	}  
	else {
	  player->set("blind",degree);
	  tell_object(player,"����۾�����һЩ, ���Կ��������\n");
	}  
	return 1;
}
