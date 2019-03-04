#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(15);
    set_name("Fat Tung","�ʶ�");
    add("id",({"fat","tung","cooker"}) );
    set_short("�ʶ�");
	set_long(@C_LONG
    �㿴��һ�����������ӣ��ֵ��ƺ����߳������Ŷ������ѣ���������ɽ���ĳ���
�����зʶ�����ɽ���ǵ�˵�����ʶ���Ĳ������������¡������Ե�ɽ������Ǯʱ��
����ȥ�����ľƵ��л�Ǯ�Է�������ѵĻ�ʳ��û��Ҫ�ԡ��ʶ����������������
������Ҫ�������ӵ�������Ϊ�����۸�����˵������ʱ��������ѧ�ա� 
C_LONG
	);
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "lizardman");
    set( "unit", "λ" );
    set_perm_stat( "dex",20);
    set_perm_stat( "str",30);
    set_perm_stat( "int",15);
    set_perm_stat( "karma",25);
    set_skill("unarmed",70);
    set_skill("block",100);
    set_skill("dodge",100);	
    set ("max_fp",800);
    set ("max_hp",1000);
    set ("force_points",800);
    set ("hit_points",1000);
    set_natural_weapon(35,20,40);
	set_natural_armor(80,40);
	set ("aim_difficulty",([ "gangolion":60,"vascular":100]) );
	set("special_defense", (["all":50,"none":20]) );
    set("attack_skill","monk/fist/tb_fist");
    set("gonfus/ho_fist",80);
    set ("weight", 800);
    set("inquiry",([
        "trouble" : "@@ask_trouble",
        "diet" : "@@ask_diet",        
        "skill" : "@@ask_skill"
        ]));
    equip_armor(TARMOR"cook_hat");
    equip_armor(TARMOR"cook_cloth");
    equip_armor(TARMOR"pot");
}
int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || (name !="cook note" && name != "diet_tea" ) ) return 1;
	if (name == "cook note") {
     if ((int)this_player()->query_temp("fat_quest/skill")<1) {
     tell_object(me,
@ANSWER1
�ʶ��ӹ��Ȿ�ʼǣ���Ҳ�������Ͱ���������յ���....
ANSWER1
);     
     item->remove();
     return 1;
}     
     if ((int)this_player()->query_temp("fat_quest/skill")==1) {
     tell_object(me,
@ANSWER2
�ʶ��ӹ��Ȿ�ʼǣ�����һ�£�˵��: ��Щ�Ҷ����ˣ����ܲ����ٰ������ʱ���??
ANSWER2
	);
        command("give "+name+" to "+(string)this_player()->query("name"));
        return 1;
}
     if ((int)this_player()->query_temp("fat_quest/skill")==2) {     
     tell_object(me,
@ANSWER3
�ʶ��ӹ��Ȿ�ʼǣ�����һ�£�˵��: ���Ǵ����ҵ���������ϵ�? ������Щ����һ
�����������óԵ�����������̫��л����!!
ANSWER3
	);
        this_player()->set_temp("fat_quest/skill",3);
        item->remove();
if ((int)this_player()->query_temp("fat_quest/diet")<4) {
write("�ʶ�˵��: ���ˣ��㲻��Ҫ���Ҽ�����? ���ڽ������??\n");
        return 1;
}
else { 
        write("������˷ʶ����񣬵õ���7000�㾭��ֵ\n");                
        this_player()->gain_experience(7000);
        return 1;
}}}
     if (name == "diet_tea")
{     
if ((int)this_player()->query_temp("fat_quest/diet")<3) {
     tell_object(me,
@DIET1
�ʶ��ӹ��Ɑ�裬�ʵ�: �������������??˵��Ѳ赹������̨
DIET
	);
        item->remove();	
	return 1;
}
else {
     tell_object(me,
@DIET2
�ʶ��ʵ�: ����Ǽ��ʲ���? ���Ὣ��һ������     
DIET2
);
command("drink diet_tea");
    item->remove();
    this_player()->set_temp("fat_quest/diet",4);
    if ((int)this_player()->query_temp("fat_quest/skill")<3) {
    write("�ʶ��ʵ�: ���ˣ����а취ʹ���������õ���������??\n");
    return 1;
    }
    else { write("������˷ʶ����񣬵õ�7000�㾭��ֵ\n");
    this_player()->gain_experience(7000);    
    return 1;
}}}}
void ask_skill()
{
if (!(this_player()->query_temp("fat_quest/fish")) || (int)this_player()->query_temp("fat_quest/fish")<3) {
write(
"�ʶ�ҡͷ˵��: ��Ҫѧ����? ����ֻ��ѧ����......\n");
}
else {
write(
"���Ǹ�һ�����˵İ����˳�ʦѧ���˵ģ���������������ζ�����ܺ������ġ�\n"
"��ϧ��ʱʱ�����ޣ���ֻѧ����������������ѣ����ǿ�ϧ��������ȥŵ����\n"
"�Ǵ�½���У��Ҿ͸���ʧȥ�����ˣ�һת���Ѿ�ʮ������....��........\n");
return 1;
}}
void ask_diet()
{
if (!(this_player()->query_temp("fat_quest/fish")) || (int)this_player()->query_temp("fat_quest/fish")<3)
write(
"�ʶ�˵��: ���������ѽ�����ǵ��Ƚ��Ŀǰ�������?\n");
else {
write(
"��һ��һʮ�İ���˳�Ļ������˷ʶ����ʶ�������ĬȻ���������ѹ������ӡ�\n"
"����Ĳ��̣������ٰ���һ��æ���跨�������ָ����������.......\n");
return 1;
}}
void ask_trouble()
{
if (!(this_player()->query_temp("fat_quest/ask")) || (int)this_player()->query_temp("fat_quest/ask")==0) 
write(
"�ʶ�˵��: ����˭��? �����������ʶ�������?\n");
else { 
write(
"�ʶ��м���˵��: �ðɣ��������������ҵ����ѡ�������������: \n"
"ʮ��ǰ����ɽ���ճ�����ʱ���Ҽ��������ǵ����С���ʱ�Ĵ�ͷĿ�ν�������һ\n"
"�����ڵ�ʳ�ã�ʹ���������ѵĻ�ʳ��������ɽկ���������ҵ������ˡ�\n"
"�����������Ҳ�����˲������飬���������ķ��ݿ��ţ������Ҳ������⣬����\n"
"�ҵĹ�Ӫ������Ȼ�ü�����Ӫ��ȥ��\n\n");
call_out("ask_trouble2",10,this_player());
}
return 1;
} 
int ask_trouble2()
{
write(
"�ʶ��������̾��һ����������˵��: \n"
"���ǳ����������Ҷ�����ɽ�Եõ�Ұ�������������˿�ʮ���ˣ���ɽ��Ұ�޼���\n"
"�챻�Թ��ˣ����仰�������Ҳ�������������.......��......\n"
"���������ϰ���˴�ںȾƣ���ڳ�������ӣ������������Ƕ��������ľƵ�ȥ\n"
"��Ǯ�Է��ˡ�����˵Ҳ��֣�Ϊʲ�����ǻ��ҵĵ���(meat)��?\n\n");
call_out("ask_trouble3",10,this_player());
return 1;
}
int ask_trouble3()
{
write(
"�����ڵ������ǣ�Ҫ��λָ���Ӫ�����������? ��ʵ��Ҳ���Ǻ�������\n"
"������⣬ֻ�ǿ�����Ҷ���Ǯȥ�Է����е����ν��ϴ��е���ⲻȥ��\n"
"�ʶ���ֿ����ס�����˵��: ��������࣬����е��ö��ˡ�\n"
"���ܰ��һָ���������⣬�ô�Ҷ�����ѳԵ��óԵ�ʳ����?\n");
this_player()->set_temp("fat_quest/meat",1);
return 1;
}
