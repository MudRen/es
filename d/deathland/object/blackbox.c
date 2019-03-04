#include "../echobomber.h"

inherit OBJECT;

mapping item_name=([ "leit_amulet":"���صĻ����(leit_amulet)",
                     "explorer_bell":"̽����֮��(explorer_bell)",
                     "crystal_card":"ˮ����Ƭ(crystal_card)",
                     "black_bottle":"��ɫƿ��(black_bottle)",
                     "study_book":"�о��ĵ�(study_book)",
                     "ancient_bottle":"�Ŵ�ƿ��(ancient_bottle)",
                     "summon_pepper":"�л������(summon_pepper)",
                     "grey_mushroom":"��ɫĢ��(grey_mushroom)",
                     "doctor_headband":"�������ķ���(doctor_headband)", 
                     "queen_amulet":"�ʺ�Ļ����(queen_amulet)",
                   ]);
void create()
{
  set_name("Black Box of Molader","Ī���µĺں���");
  add("id",({"box"}));
  set_short("Black Box of Molader","Ī���µĺں���");
  set("long","@@long_description");
  set("quest_item",([]) );
  set("quest_action",([]) );
  set( "unit", "��");
  set("weight", 0);
  set("prevent_drop",1);
}

//int query_auto_load() { return 1;}

void init()
{
    add_action("check_item","box_check");
    //  special action  //
    add_action("to_drink","drink");
    add_action("to_durance","durance");
    add_action("to_show","show");
    add_action("to_release","release");
    add_action("to_summon","summon");
    add_action("to_mix","mix");
    //  specail action  //
}

string long_description()
{
     int i;
     string long_1;
     mixed names;
     long_1 = "����һ������ĺ�ɫ����, ������Դ��һЩ��������������Ʒ.\n"+
           "������� <box_check> ȥ��Ŀǰ�ںں�������Ķ���.\n"+
           "Ŀǰ��ں���������...\n" ;
     names=keys(query("quest_item"));
     for(i=0;i<sizeof(names);i++) 
         long_1 += query("quest_item/"+names[i])? item_name[names[i]]+"\n":"";  
     return long_1;
}

int check_item(string str)
{
    string *name;
    int i;
    
    if(!str||str=="") return 0;
    name=keys(query("quest_item")); 
    for(i=0;i<sizeof(name);i++) 
      if (str==name[i]) { 
        write(item_name[str]+".\n");
        call_other(this_object(),"look_"+name[i],this_player());   
        return 1;
        }
    write("��ĺں���û�������.\n");
    return 1;
}

void look_leit_amulet(object who)
{
     tell_object(who,
     "�������صĻ����. ����д����һЩ���ص�����, Ӧ����һ����ʥ��ף��.\n"
     );
     return;
}

void look_explorer_bell(object who)
{
     tell_object(who,
     "һ������̽�ռҵ�����, �ƺ�����ָ���㵽һ�����صĵط�.\n"
     +(query("quest_action/invoke_bell")? "(�ѱ�ʩչ���ر�ħ����)"
      : "(������֪�����������)" ) + "\n"
     );
     return;
}

void look_crystal_card(object who)
{
     tell_object(who,
     "һ��ˮ���Ƶ����⿨Ƭ, ���˻ᷢ���������Ϲ���, �ƺ��������ڷ���һ\n"
     "���ر������.\n"
     );
     return;
}

void look_black_bottle(object who)
{
     int i;
     string c_muse;
     if ( (i=query("quest_action/muse_filled")) )
     c_muse=call_other(Deathland"/dwarf/daemon/muse","muse_color",i);
     tell_object(who,
     "һ����˵����ʢװһ��Һ��ĺ�ɫƿ��.(Ŀǰ"
     +( i ?"��װ����"+c_muse+"ɫ����˼Ȫˮ":"�ǿյ�" )+")\n"
     );
     return ;
}

void look_ancient_bottle(object who)
{
     tell_object(who,
     "һ�����صĹŴ�ħ��ƿ��."+( !query("quest_action/charge_bottle")?   
     "(��δ��ע������)\n": "(�ɽ�������)"+( query("quest_action/bottle_lock")?
     "(Ŀǰ������"+(string)query("quest_action/bottle_lock")+"�����)":"")+"\n"
     "���������ƿ��������(durance)���,Ҳ���԰�����ƿ�����ͷ�(release)����.\n"
     ) );
     return;
}

void look_study_book(object who)
{
     tell_object(who,
     "һ������д��������ֹ����ֵ���, �ƺ���һ���о��ĵ�.\n"
     );
     return;
}

void look_summon_pepper(object who)
{
     tell_object(who,
     "һƿ��ֵĺ�����, ��˵�����л�(summon)��ȥ�����(spirit).\n" 
     );
     return;
}

void look_grey_mushroom(object who)
{
     tell_object(who,
     "������ժ���Ļ�ɫĢ��.\n"
     );
     return ;
}

void look_doctor_headband(object who)
{
     tell_object(who,
     "���ǰ������ķ���,�ƺ��ܹ����������ǰ�������ʹ��.����԰���չʾ(show)\n"
     "�����˿���֤ʵ������.\n"
     );
     return;
}

void look_queen_amulet(object who)
{
     tell_object(who,
     "���ǻʺ�����˿�Ļ����, �ǻʺ��ø���ȥ��������ʱ, ֤ʵ�������õ�.\n"
     );
     return;
}

int to_drink(string str)
{ 
     if (!str||str=="") return 0;
     if ( ! query("quest_action/muse_filled") ) return 0;
     if ( str=="water" || str=="bottle")
        write(
        "��ȷ��Ҫ������ƿ���ڵ�Ȫˮ��??��Ȫˮ������ȫȫ��֪������������ɷ�\n"
        "����������Ѿ��˽��������ԵĻ�, �ͺȰ�! ����û���˻ᱣ֤����������\n"
        "�ᷢ��.\n"
        "�� < drink bottle_water > ȥ������Ȫˮ��!!\n"
        ); 
     else if ( str=="bottle_water") 
        call_other(Deathland"/dwarf/daemon/muse","drink_bottle_muse",this_player(),this_object() );
     return 1;
}

int to_durance(string str)
{
    object *monster;
    int i;
    string c_str,p_str;
    
    if (!str||(str!="leit"&&str!="falady") ) return 0;
    if ( ! query("quest_action/charge_bottle") ) return 0;
    if ( (p_str=query("quest_action/bottle_lock")) ) 
        {
          c_str= (p_str=="leit")?"����":"������";
          write("���ƿ�����Ѿ�����"+c_str+"�������.\n");
          return 1; 
        }
    monster=all_inventory(environment(this_player()));
    for(i=0;i<sizeof(monster);i++) 
      if ( monster[i]->query("can_be_duranced") ) {
      call_other(monster[i],"durance",this_player(),this_object() );
      monster[i]->remove();
      return 1;
      } 
    return 0;  
}

int to_release(string str)
{
    string p_str,c_str;
    object room;
    
    if (!str||(str!="leit" && str!="falady") ) return 0;
    if ( ! query("quest_action/charge_bottle") ) return 0;
    if ( ! (p_str=query("quest_action/bottle_lock")) ) return 0;
    c_str= (p_str=="leit")?"����":"������";
    if (p_str!=str) {
    write("���ƿ����������"+c_str+".\n");
      return 1;
      }
    
    if ( ( room=environment(this_player()) )->query("echo_special_place") ) 
      call_other(room,"release",this_player(),this_object()); 
    else {
     write(c_str+"����걻�ͷ���, һ���Ӿ���ʧ����Ӱ������.\n");
     delete("quest_action/bottle_lock");  
     }
   return 1;  
}

int to_mix(string str)
{
    int color;
    if (!str||str=="") {
      if ( ! query("quest_item/grey_mushroom") ) 
        return 0;
      if ( ! (color=query("quest_action/muse_filled") ) ) {
        write("��û��װ��˼Ȫˮ.\n");
        return 1;
        }
      write("���Ģ������װ����˼Ȫˮ��ƿ���ڻ��.\n");
      set("quest_action/mixed",1);
      return 1;    
      }
    return 0;
}

int to_show(string str)
{
    object player;
    object *monster;
    int i;
    
    player=this_player();
    if (!str|| str!="headband") return 0;
    if ( ! query("quest_item/doctor_headband") ) 
        return 0;
    
    monster=all_inventory(environment(player)); 
    for (i=0;i<sizeof(monster);i++) 
      if  (  monster[i]->id("molader") && monster->query("npc") ) {       
        call_other(monster[i],"show_headband",player);
        return 1;
        }
    write("��ѷ����ó���չʾ.\n");
    return 1;
}

int to_summon(string str)
{
    object room;
    if (!str||str!="spirit") return 0;
    if (! query("quest_item/summon_pepper") ) return 0;
    if ( ( room=environment(this_player()) )->query("echo_special_summon") ) 
      call_other(room,"summon",this_player(),this_object());    
    else 
      write("�㳢���������л����, ����û���κ����鷢��.\n");
    return 1;  
}
