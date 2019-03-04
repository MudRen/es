#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set_name("antidote pill", "�ⶾ��" );
	add( "id", ({"pill"}) );
	set_short("an antidote pill", "�ⶾ��");
	set_long(
		"You see an antidote mixture of healers. You can eat it to\n"
		"cure poison.\n",
		"����һ����ҽ��������Ľⶾ�裬��(eat)�������Խ��һ�㶾�ߡ���\n"
		"��Ķ��ԣ���춱Ƚ��صĶ����м����ж�ʱ���Ч����\n"
	);
	set( "can_eat", 1 );
	set( "unit", "��" );
	set( "weight", 15 );
	set( "value", ({ 50, "silver" }) );
	set( "medication", 50 );
}

void eat(object player)
{
	mixed *cond_data;
	if( !player->query("conditions/simple_poison") ) return;

	cond_data = player->query("conditions/simple_poison");
	if (!sizeof(cond_data) == 3) return;

	if (cond_data[1] >= 6)
	{
	    cond_data[1] /= 2;
	    player->set("conditions/simple_poison", cond_data);
	    tell_object(player, "����ú�һ���� ....\n");
	}
	else
	{
	    tell_object( player, "�����еĶ�����ˣ�\n" );
	SIMPLE_POISON->remove_effect(player);
	}
}
