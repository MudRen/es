#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(1);
	set_name( "Spirit of dwarf Prince Falady", "�������ӷ����ڵ����" );
	add ("id", ({ "prince", "falady", }) );
	set_short( "Spirit of Dwarf Prince Falady", "�������ӷ����ڵ����" );
	set_long(
    "a spirit of falady .\n",
	"�����ڵ����.\n"
	);
    set("can_be_duranced",1);
    set("no_attack",1);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_natural_weapon(1,1,1);
	set_natural_armor(10,10);
}

void durance(object player,object box)
{
   if ( box->query("quest_item/queen_amulet") ) {
     tell_object(player,
      "��ѷ�����׽����ƿ����.\n");
      tell_room(environment(player),
        "�����ڱ�"+player->query("name")+"��׽����ƿ��.\n",
        player );
     box->set("quest_action/bottle_lock","falady");   
     }
   else {
     tell_object(player,"������Ϊ���ӱ����ħ������ʧ��.\n");
     tell_room(environment(player),
     "������Ϊ���ӱ�"+player->query("name")+"��ħ������ʧ��.\n",player);
     }  
   return ;
}
