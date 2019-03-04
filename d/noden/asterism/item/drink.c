/* drink interface  Elon@Eastern.Stories -Sun  06-26-94 */
/* alternative until someone turn on the drinking mode  */
/* Sat  07-23-94  Sun  07-31-94                         */
/* Sun  07-31-94  Mon  08-01-94                         */
/* please INHERIT this object.                          */
//
//    The original drink can only be drunk by Name
//    Changed to check id By Indra@Eastern.Stories  
//                                 On Sat 09-17-94    
//    need to restrict the amount that players can drink.
 
#include <mudlib.h>
#include <config.h>

#define EMPTY_CON "/d/translate/tmp/"
 
inherit OBJECT;
 
int drink_me();
void make_empty_con(object drink);
int drink_effect();
void disp_msg(int i);
 
void create()
{
    seteuid(getuid());
   set_short("��ͨ����");
   set_long("����һƿ��ͨ������, ����Բ�Ӧ�ÿ�����.\n");
    set("drink",1);
    set("weight",5);
    set("unit","ƿ");  // ƿ, ��, ��, ��(?)
    set("recycle",10); // recycle value, reset if needed. type is copper.
    set("tp",0);
    set("hp",0);
    set("sp",0);
// this is a weird property.. if =1, WILL NEVER disappear after drink
// =1 will make an unlimited drink :)
    set("keep",0);
    set("value",({50,"silver"}));
    set("container",1);  // container = 0 has no empty container..
    set("amount",20); // for quota.....
/*  set drink message if need customize.. $EN = English name, $CN = Chinese
    set("c_succ","�����һƿ����\n");
    set("c_osucc","$CN�ȵ�һƿ����\n");
*/
    set("c_fail","���Ժ���һƿ����, ���Ƕ���������.\n");
    set("c_ofail","$CN��������һƿ����, ��ϧ����������.\n");
}
 
void init()
{
    add_action("check_syn","drink");
}
 
int check_syn(string str)
{
    if (!str || !id(str) ) {
        return notify_fail(
        "��ʲ��?\n");
    }
    if ( environment() != this_player() ) {
        return notify_fail(
          "������û�����ֶ�����\n" );
    }
    return this_object()->drink_me();
}
 
// function to call when drink_effect returns 1
void disp_msg(int i)
{
    string code;
   string c_unit;
   string  my_c_msg, ur_c_msg;
    string tmp_str, str1, str2;
    int tmp_val;
    c_unit=(string)this_object()->query("unit");
    if (i==1) {
        code="succ";
    }
    else {
        code="fail";
    }
// all the IFs will be useless if code=fail, cuz fail has default.
    if (!this_object()->query("c_"+code)) {
        my_c_msg="�����һ"+c_unit+this_object()->query("c_short")+".\n";
    }
    else {
        my_c_msg=(string)this_object()->query("c_"+code);
    }
    if (!this_object()->query("c_o"+code)) {
        ur_c_msg=this_player()->query("c_name")+"����һ"+c_unit+this_object()->query("c_short")+".\n";
    }
    else {
        ur_c_msg=(string)this_object()->query("c_o"+code);
        tmp_val=sscanf(ur_c_msg,"%s$CN%s",str1,str2);
        if (tmp_val!=2) {
            ur_c_msg=(string)this_player()->query("c_name")+ur_c_msg;
        }
        else {
            ur_c_msg=str1+(string)this_player()->query("c_name")+str2;
        }
    }
   write( my_c_msg );
   tell_room(environment(this_player()),ur_c_msg,({this_object(),this_player()}) );
}
 
int drink_me()
{
    // if drink_effect return 1, will display succ, otherwise fail
    disp_msg(drink_effect());
    // taking care of left overs
    if ((int)this_object()->query("keep")==0) {
        if (this_object()->query("container")) { // container yes
            make_empty_con(this_object());
        }
        this_object()->remove();
    }
    return 1;
}
 
int drink_effect()
{
    int cur_tp, cur_hp, cur_sp;
    int max_tp, max_hp, max_sp;
    int new_tp, new_hp, new_sp;
// drink effect (kinda dumb method to handle it.. but heck.. it works.
// if it already/will max out, use the highest value.
    cur_tp=(int)this_player()->query("talk_points");
    max_tp=(int)this_player()->query("max_tp");
    new_tp=cur_tp+(int)this_object()->query("tp");
    if (new_tp > max_tp )
    new_tp=max_tp;
    this_player()->set("talk_points",new_tp);
    cur_sp=(int)this_player()->query("spell_points");
    max_sp=(int)this_player()->query("max_sp");
    new_sp=cur_sp+(int)this_object()->query("sp");
    if (new_sp > max_sp )
    new_sp=max_sp;
    this_player()->set("spell_points",new_sp);
    cur_hp=(int)this_player()->query("hit_points");
    max_hp=(int)this_player()->query("max_hp");
    new_hp=cur_hp+(int)this_object()->query("hp");
    if (new_hp > max_hp )
    new_hp=max_hp;
    this_player()->set("hit_points",new_hp);
    return 1;
}
 
void make_empty_con(object drink)
{
    object empty;
   string c_unit;
    int val;
 
    val=(int)drink->query("recycle");
    c_unit=(string)drink->query("unit");
 
    empty = new(EMPTY_CON+"empty");
   empty->set_name(c_unit+"��");
    empty->set("recycle",val);
    empty->move(environment(drink));
}
 
