#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "merchant", "�㷷" );
	add( "id", ({ "fish merchant" }) );
	set_short( "�㷷" );
	set_long("һ����������ͨͨ���㷷��\n");
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 100 );
	set_skill( "dodge", 40 );
	set( "wealth/gold", 5 );
	set( "natural_weapon_class1", 4 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 5 );
        set( "inquiry", ([
	        "fish": "@@ask_fish",
                "cook": "@@ask_cook"
        ]) );
}
int ask_fish()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/skill")) || this_player()->query_temp("fat_quest/skill") < 1) {
write(
"�㷷˵�����ҵ���ܺóԵ�Ӵ??\n");
}
else {
write(
"�㷷Ц��: ��������Ӻ�����ͻۣ�Ҫ��Ҫ�ҽ�����������(cook)����?\n");
return 1;
}
}
int ask_cook(int ob1)
{
      if ( present("cook note",this_player()) ) {
write(
"�㷷˵��: ����û��ʲ����Գ������ģ�������Ų������ǡ������ѳ�ʦ�ıʼ�\n"
"�ø��㷷��ֻ�����ڱʼ���ͿͿдд֮�ᣬȻ������İѱʼǻ���.....\n");
this_player()->set_temp("fat_quest/skill",2);
return 1;
}
else 
    write("�㷷˵��: ����û�бʼ�֮��Ķ�����??\n");
    return 1;
}
