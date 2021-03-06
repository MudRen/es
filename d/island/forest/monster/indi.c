#include "../tsunami.h"

inherit MONSTER;

void create()
{
    object obj;

    ::create();
    set_level(3);
    set_name("Adventurer Indiana Jones","琼斯");
    add("id",({"anventurer","indiana","jones","indi"}) );
    set_short("伟大的冒险家 印地安那琼斯");
    set_long(@LONG
印地安那琼斯是一为非常活耀的冒险者，虽然是大学中考古系的教授，却热衷
於为博物馆收集各种古代的文化遗迹；这一次，他搜寻的是隐蔽在层层天险之
中的魔族秘境。
LONG);
    set("unit","位");
    set("race","human");
    set("gender","male");
    set("class","adventurer");
    set("weight",600);
    set("alignment",500);
    set_perm_stat("str",5);
    set_perm_stat("dex",3);
    set_skill("dodge",10);
    set("hit_points",100);
    set("max_hp",100);
    set("wealth/silver",100);
    set_natural_weapon(10,3,10);
    set_natural_armor(10,0);
    set("chat_chance",5);
    set("chat_output",({
 "琼斯喃喃道：那个老头到底是遭到什麽横祸？怎麽会将研究一辈子的考古笔记寄给我?\n"
     }) );
    wield_weapon(TWEP"whip");
    set("inquiry", ([
        "note":"@@ask_note"
        ]) );
    obj = new(TOBJ"bag");
    obj->move(this_object());
//    note = new(TOBJ"note");
//    note->move(obj); 
}
void ask_note(object asker)
{
    
     if( this_object()->query("noted") ) 
     tell_object( asker,
     "\n琼斯说道：你晚来一步，笔记本已经有人取走了。
\n"); 
   
     else {
     this_object()->set("noted",1);
     tell_object( asker,
     "\n琼斯说道：好吧 !! 也算了却我一桩心事。\n"); 
     call_out("rebo1",3,asker);    
     call_out("rebo2",2000,this_object());
     }
}     
void rebo1(object ob1)     
{    
     object note;
     note = new(TOBJ"note"); 
     note->move(this_object());
     command("give note to "+ob1->query("name"));
}
void rebo2(object ob)
{
     ob->delete("noted");
}  

    

