#include "../tsunami.h"

inherit MONSTER;

void create()
{
    object obj;

    ::create();
    set_level(3);
    set_name("Adventurer Indiana Jones","��˹");
    add("id",({"anventurer","indiana","jones","indi"}) );
    set_short("ΰ���ð�ռ� ӡ�ذ�����˹");
    set_long(@LONG
ӡ�ذ�����˹��һΪ�ǳ���ҫ��ð���ߣ���Ȼ�Ǵ�ѧ�п���ϵ�Ľ��ڣ�ȴ����
�Ϊ������ռ����ֹŴ����Ļ��ż�����һ�Σ�����Ѱ���������ڲ������֮
�е�ħ���ؾ���
LONG);
    set("unit","λ");
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
 "��˹�૵����Ǹ���ͷ�������⵽ʲ����������Ὣ�о�һ���ӵĿ��űʼǼĸ���?\n"
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
     "\n��˹˵����������һ�����ʼǱ��Ѿ�����ȡ���ˡ�
\n"); 
   
     else {
     this_object()->set("noted",1);
     tell_object( asker,
     "\n��˹˵�����ð� !! Ҳ����ȴ��һ׮���¡�\n"); 
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

    

