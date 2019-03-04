#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set_name("minor spirit pill", "����" );
	add( "id", ({"spirit", "pill"}) );
	set_short("a minor spirit pill", "����");
	set_long(
		"You see a small white pill with cool smell.\n",
		"����һ��ɢ��������ζ���İ�ɫ��ҩ��\n"
	);
	set( "medication", 20 );
	set( "effect_critical",20);
	set( "can_eat", 1 );
	set( "unit", "��" );
	set( "weight", 15 );
	set( "value", ({ 250, "silver" }) );
}

void eat(object player)
{
	int max, sp;

	if( !max = player->query("max_sp") ) return;
	if( (sp=player->query("spell_points")) >= max ) return;
          if(this_player()->query("class")=="mage")
    {
	tell_object( player, "�������ķ����ָ��ˣ�\n" );
    }
         else { tell_object(player, "�������ľ������ָ��� ��\n" ); }
	if( sp + 50 > max ) player->set("spell_points", max);
	else player->set("spell_points", sp+50 );
}
