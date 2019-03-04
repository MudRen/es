#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "tea girl", "�������" );
	add( "id", ({ "girl" }) );
	set_short( "�������" );
	set_long(@C_LONG
��λ������￴�������ֻ��ʮ�塢���꣬��Ц����������������
�ľ��С�
C_LONG
   	        );
	set( "gender", "female" );
	set( "race", "human" );
	set( "no_attack", 1 );
	set( "chat_chance", 10 );
	set( "chat_output", ({
		"����������ض�����΢Ц��\n",
		"�������˵��: ��ү�����ȱ��裬ЪЪ�Ȱɡ�\n",
		"�������˵��: ���ǵĲ�Զ������������ֹ�ʡ�\n",
		"�������˵��: ��ӭ���٣����������\n"
	}) );
        set( "inquiry", ([
	        "diet": "@@ask_diet",
	        "brother": "@@ask_brother"
        ]) );
}
void init()
{
    ::init();
    add_action("do_answer","answer");
}
int ask_diet()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/diet")) || this_player()->query_temp("fat_quest/diet")<1) {
write(
"�������������һ���ƣ����: ����������? ��Ҫ������??\n");
}
else {
write(
"\n�������˵��: û���������������ʲ裬�����ҾͿ��°��ˣ���ɲ���������\n"
"����??\n");
command("giggle "+(string)this_player()->query("name"));
return 1;
}
}
int ask_brother()
{
if (this_player()->query_temp("fat_quest/diet")<1) {
write(
"�������˵��: ����˭��? �����ʶ�������...\n");
return 1;
}
else {
write(
"\n�������˵��: û��������һ����磬��������ȫ�����Ե����Ź֣���С�Ͳ�\n"
"̫�չ��ң�һ�쵽�������β�ȥ��������Ϊ������Ψһ�ĸ�磬��Ҳ�������𾴣�\n"
"��һ�죬����һ����������һ�Ŵ����飬�������С�ͷǳ�ϲ�����飬�������Ͱ���\n"
"���͸��ң���������ڿ����Ҽ��䣬������������ҳ��������������룬��Ҳ������\n"
"��............................\n\n");
call_out("ask_brother1",10,this_player());
return 1;
}
}
int ask_brother1()
{
write(
"����������˵��: ��������ҩζ�����Ҹ�������İ�? ������˵����ã�ֻ��\n"
"���̫���ˣ��������Ͼ����Ҹ�磬�ȵ���������һ���䣬�һ��ȥ��������\n");
return 1;
}
int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || (name!="blue pearl" && name != "pearl ring" && name != "Moon pearl") ) return 1;
	if (name == "pearl ring")
{
     tell_object(me,
@RING
�������ӹ������ָ�������˼��ۣ�˵��: ����Ĭ��˹�����ļ����顣���������
�տ����ͻῴ����\��СС���ݡ�˵�꣬�������ѽ�ָ������.....
RING
	);
        command("give "+name+" to "+(string)this_player()->query("name"));
        return 1;
}
     if (name == "blue pearl")
{     
     tell_object(me,
@BLUE
�������ӹ������飬���˼�����ҡҡͷ˵��: ����������Ȼ����Ʒ�������ֺ�Ư����
���Ǹ���Ĭ��˹�˵Ľ�������ɫ����Ϊ�ܵ�ħ��Ԫ����Ⱦ�Ľ�����������棬������
���в��õ�Ӱ�죬�����С��һ�㡣˵�꣬�������ѽ�ָ������.....
BLUE
	);
        command("give "+name+" to "+(string)this_player()->query("name"));
        return 1;
}
     if (name == "Moon pearl")
{     
     tell_object(me,
@MOON
�������ӹ�ҹ���飬���ۺ�Ȼһ������ʼ������Ŵ����飬������¶���������ֵ�
����........
MOON
	);
	item->remove();
call_out("play_pearl",20,this_player());
	return 1;
}
}		
int play_pearl(object me)
{
write("ʮ�������ᣬ����������̧��ͷ����˵��: ��������治������Ҫ�������ҵ���?\n"
      "(answer yes or no)...........\n");
		me->set_temp("fat_quest/diet",2);
        return 1;
}
int do_answer(string arg,object ob1)
{
   if (this_player()->query_temp("fat_quest/diet")<2) return 0;
   if (this_player()->query_temp("fat_quest/get_tea")) return 0;
   if ( !arg || (arg != "yes" && arg != "no")) {
   write(
@ANSWER1
����������: ��Ҫ�°��ˣ�Ҫ���ǲ�Ҫ��.....
ANSWER1
);
return 1;
}
   if ( arg == "yes" ) {
   write(
@ANSWER2
�������Ц�������Ҿ�лл���������ˣ��㲻��Ҫ����ʲ���? ���������һ��
˵�꣬����������ְ˽ŵ�����һ������㡣
ANSWER2
);
   
   ob1 = new("/d/eastland/liang_shan/obj/diet_tea");
   ob1->move(environment(this_object()));  
   this_player()->set_temp("fat_quest/diet",3);
   this_player()->set_temp("fat_quest/get_tea",1);
return 1;
}
   if ( arg == "no" ) {
   write(
@ANSWER3
����������: ˣ�Ұ����Ҷ����°��˻��˷���ʱ��......˵�����������ͷ��
��ȥ����������Ѫ���죬����Ҳ�����ˡ�
ANSWER3
);
   return 1;
}
}