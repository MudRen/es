#include <mudlib.h>

inherit WEAPON;
int check_level();

void create()
{
       set_name("angry of god","������֮ŭ��");
      set_short("angry of god","������֮ŭ��");
       add("id",({"polearm","god"}));
       set_long(@C_LONG
�����������ĳ�ì��������ǰ����а��ʦ���꣬��˾
�ȿ�Ů���������Ǵ�ս��ʱ�������µ�һ��̴ľ�ȼ���
��ħ���ۼ�ڤ���������߳ɵĳ�ì����춼�������ڤ��
�������ںϳɣ����治ͣ����¶��һ�ɺ����������ڳ�
ì�����ܡ�
C_LONG );
      set("unit","��");
      set("weight",245);
      setup_weapon("polearm",50,30,40);
      set("bleeding",5);
      set("no_sale",1);
      set("no_clean",1);
      set("value",({1000,"copper"}));
      set("hit_func","my_tactic");
      set("special_damage","@@check_level");
      set("c_msg","\n������֮ŭ���롺����Ļƻ衻ͻȻ��������Ѽ��⣬\n"
              "\n �л�ǧ��ֻڤ��֮��������ˣ���\n\n");
}
void report(object attacker,object victim)
{
  seteuid(getuid());
  tell_object(victim,sprintf("��%s)\n","/adm/daemons/statsd"->status_string(victim)));
  return ;
}
int fail_to_use(object holder) {
     object ob;
      if (!ob = (object)holder->query("weapon2"))
              return 1;
    if ((string)ob->query("c_name")!="������Ļƻ衻")
              return 1;
     return 0;
}
int special_hit_rate(){
   object holder,victim;
   holder = environment(this_object());
   victim = holder ->query_attacker();
   if ((int)victim->query_level()>15) return 33;
   else
    if ((int)victim->query_level()>9) return 40;
    return 90;
}
string special_type() {return "none";}
int check_level()
{
  object holder,victim;
  holder = environment(this_object());
  victim = holder->query_attacker();
  if ((int)victim->query_level()>15) return 120;
  else
   if((int)victim->query_level()>9) return 140;
   return 350;
}
int my_tactic()
{
  object holder,victim;
  string c_msg;
  int dam;

  if(!holder = environment(this_object())) return 0;
  if(!victim = holder->query_attacker()) return 0;
  if(fail_to_use(holder)){
      tell_room(environment(holder),
     holder->query("c_name")+"�ġ�����֮ŭ��ͻȻ����һ����������ͻȻ���ѡ�\n\n",holder);
     tell_object(holder,"��ġ�����֮ŭ��ͻȻ����һ����������ͻȻ���ѡ�\n\n");
      setup_weapon("polearm",30,14,28);
               add("long","\t\tȴ�Ѿ�ֻʣ��ľ���ˣ���\n");
      delete("hit_func");
      holder->calc_weapon_class();
      return 0;
      }
  if(random(100)<special_hit_rate()){
      c_msg = (string)query("c_msg");
      dam = (int)query("special_damage");
      victim->receive_special_damage(special_type(),dam);
      tell_object(holder,set_color(sprintf(c_msg,
             "��",victim->query("c_name")),"HIM",holder));
          tell_object(victim,set_color(sprintf(c_msg,
            holder->query("c_name"),"��"),"HIM",victim));
          tell_room(environment(holder),
            sprintf(c_msg,holder->query("c_name"),
          victim->query("c_name")),({holder,victim}));
          report(holder,victim);
       return 1;
       }
   return 0;
}

