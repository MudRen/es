#include <saulin_temple.h>
#define SLAB_FILE "/d/eastland/data/brassman.txt"

inherit ROOM;

void create()
{
        ::create();
        set_short( "铜人阵入口" );
        set_long(
@C_LONG
你现在来到了少林寺闻名天下的铜人阵前，这儿是少林寺为了测验门下弟
子是否具备了足够的能力去除妖辟邪、主持正义，而设置的试炼。能够通过这
儿考验的少林弟子都是其同侪中的佼佼者，出外则代表少林寺，因此少林寺众
弟子莫不视能通过铜人阵为最大的荣耀。当然也有些弟子因为六根不净而想还
俗，此时少林的长老们就会以通过铜人阵与否，来决定其是否可以还俗。你看
到旁边立了块石碑(slab)，上面有些字。
C_LONG
        );
 	set_outside("eastland");
 	set( "enter", 0);
        set( "exits", ([
        	"east" : SAULIN"stone_path3",
                "south" : SAULIN"grass2",
                "west" : SAULIN"grass0"
        ]) );
        set( "item_desc", ([
        	"slab" : "@@read_slab" ]) );
        set( "objects", ([
        	"elder#1" : "/d/eastland/saulin_temple/brass/obj/elder" ]) );
}

void init() 
{
	add_action("do_answer", "answer");
}

int do_answer(string str)
{
	object obj;
	obj = this_player();
	
	if( !str || str == "" ) return 0;
	if( !obj->query_temp("brassman") ) return 0;
	
	if( str == "yes" ) {
		if( this_object()->query("enter") ) {
			tell_object(obj,
				"慧元大师唱了声佛号，说道：已经有人进入铜人阵了。\n" );
			return 1; };
		if( (int)obj->query("monk_score") < 3600 ) {
			tell_object(obj,
				"慧元大师说道：你对少林寺的贡献不够，不得进入。\n" );
			return 1; };
	 	if( (string)obj->query("class") != "monk" ) {
			tell_object(obj,
				"慧元大师唱了声佛号，说道：少林重地，施主请留步。\n" );
			return 1; };
		if( (int)obj->query_level() < 14 ) {
			tell_object(obj,
				"慧元大师唱了声佛号，说道：你能力不足，还是不要轻易冒险吧。\n" );
			return 1; };
		if( (int)obj->query("18brass") ) {
			tell_object(obj,
				"慧元大师说道：你已通过考验了。\n" );
			return 1; };
		tell_object(obj,
			"慧元大师说道：阿弥陀佛。铜人阵过关不易，若是你觉得体力不支的话\n"
			"	      ，以击壁(knock wall)为号，自然有人会救你出来，千\n"
			"	      万不要逞强。请先准备一下吧 !!\n" );
		obj->set_temp("block_command",1);
		call_out("enter_brass",4,this_player());
		return 1;
		}
	else return 0;
}

int enter_brass(object who) 
{
	tell_object(who,
			"慧元大师打开了一道暗门，将你送了进去。\n" );
	who->delete_temp("block_command");
	who->move_player(SAULIN"brass/zeng1","SNEAK");
	this_object()->set("enter",1); 
	return 1;}

int clean_up() { return 0; }

string read_slab()
{
	this_player()->more(SLAB_FILE);
	return "\n";
}
