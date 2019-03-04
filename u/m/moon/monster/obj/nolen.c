#include <mudlib.h>
#include "../farwind.h"
inherit MONSTER;

int perform_marriage();
int perform_marriage2();
int perform_marriage3();
int perform_divorce();
void create()
{
        ::create();
    seteuid(getuid());
        set_level(5);
        set("exp_reward",0);
        set("race","human");
        set_name("Nolen","ŵ��");
        set_short("��ʦŵ��");
        set_long(@TEXT
������ǰ����һ�����θߴ�, ����������������ʦ����ʦ. �����ð
�վ��������, ������ΪҪ��ĳ�˵�׷ɱ�������ﵱ��ʦ��.
��������˵����... ��Ȼ����������, ��Ҫ���Ҳ������������.

TEXT
        );
        set("max_tp",1500);
        set("talk_points",1500);
        set("no_attack",1);
        enable_commands();
        set("wait");
    set("step",1);
    set("husband");
    set("wife");
    set("witness");
    set("male_agree",0);
    set("female_agree",0);

}

void init()
{
        ::init();
        add_action("wait_answer","answer");
        add_action("do_nod","agree");
        add_action("do_shake","refuse");

}

int perform_marriage()
{
    string n1,n2;
        object ob;
    n1=capitalize((string)query("husband"));
    n2=capitalize((string)query("wife"));
    ob=present((string)query("husband"), environment(this_object()));
    if (!ob) {
        command("say ��... Ц������, �����������Ӱ�?!?");
        command("shake");
        command("say ���˰���... �´ΰ�!\n");
        set("husband");
        set("wife");
        set("witness");
        set("wait");
        set("step",1);
        return 1;
    }
    command("say "+n1+", ��Ը��Ȣ"+n2+"Ϊ��, ����ӦҪ�ú��չ���,");
        command("say ���۾������� reboot, crash �� lag, ���������ذ�������,"); 
        command("say ׬Ǯ������, �����������˺���?");
    tell_object(ob, "ŵ�׻�ͷ����˵: ��ش�(answer) Yes �� No.\n");
    set("wait",lower_case(n1));
        return 1;
}

int perform_marriage2()
{
    string n1,n2;
    object ob, ob1;
    n1=capitalize((string)query("husband"));
    n2=capitalize((string)query("wife"));
    ob=present((string)query("wife"), environment(this_object()));
    ob1=present((string)query("husband"), environment(this_object()));
    if (!ob1) {
        command("say ��... Ц������, �����������Ӱ�?!?");
        command("shake");
        command("say ���˰���... �´ΰ�!\n");
        set("husband");
        set("wife");
        set("witness");
        set("wait");
        set("step",1);
        return 1;
    }
    command("say "+n2+", ��Ը��޸�"+n1+", �����ɹ� reboot, crash �� lag.");
    command("say ������Ǯ, �ռ�װ����?");
    tell_object(ob, "ŵ�׻�ͷ����˵: ��ش�(answer) Yes �� No.\n");
    set("wait",lower_case(n2));
        return 1;
}

int perform_marriage3()
{
    string n1,n2,n3;
    object ob, ob1, ob2;
    n1=capitalize((string)query("husband"));
    n2=capitalize((string)query("wife"));
    n3=capitalize((string)query("witness"));
    ob=present((string)query("witness"), environment(this_object()));
    ob1=present((string)query("husband"), environment(this_object()));
    ob2=present((string)query("wife"), environment(this_object()));
    if ((!ob) || (!ob1) || (!ob2)) { //anyone of them is missing
        command("say ��... �˲����˻���ʲ��鰡.. ���˰���..");
        return 1;
    }
    if (wizardp(ob)) { // witness is a wizard
    command("smile");
    command("say �����ڹ�֤��"+n3+"����ҵ���ǰ, ������������ʽ��Ϊ����!");
    command("shout "+n1+" �� "+n2+" ����ʦ��ף���½�Ϊ������, ���ף������!!!!!");
    command("say "+n1+", �������������!\n");
    command("grin");
    tell_room(environment(this_object()),
    "ŵ��ͻȻ������, ������������.\n",this_object());
    command("hold "+n2);
    command("kiss "+n2);
    command("kiss "+n2);
    command("lkiss "+n2);
    command("say ��.. ����������.\n");
    }
    else {
    command("grin");
    command("say �� ES �Ĺ��, û����ʦ����֤�˵Ļ�����˽��.");
    command("say ������, ��Ȼ���������మ, �Ȳ�����...");
    command("grin");
    command("say �����ڹ�֤��"+n3+"����ҵ���ǰ, ������������ʽ��Ϊ����!");
    command("shout "+n1+" �� "+n2+" ˽�����!!!!!");
    command("say "+n1+", �������������!\n");
    }
    command("grin");
    command("say ף�����Ҹ�!\n");
    command("shout ��... �������ľ�ͷ!!!");
    set("husband");
    set("wife");
    set("witness");
    set("wait");
    set("step",1);
    ob1->set("spouse",n2);
    ob2->set("spouse",n1);
        FARWIND"church"->marriage_done(n1,n2);
    return 1;
}


int wait_answer(string str)
{
        if (!query("wait")) {
    tell_room(environment(this_player()),(string)this_player()->query("c_name")+
    "���ֹ����ز�֪���ڸ���ʦ˵ʲ��.\n",({this_player(), this_object()}));
    command("?");
        return 1;
        }
        if ((string)this_player()->query("name")!=query("wait"))
        {
    tell_object(this_player(),"��˵��: ��Ը��!\n");
    tell_room(environment(this_player()),(string)this_player()->query("c_name")+
    "˵��: "+"��Ը��!\n",({this_player(), this_object()}));
    command("slap "+(string)this_player()->query("name"));
    command("say "+capitalize((string)this_player()->query("name"))+", �Ҳ�������!");
        return 1;
        }
    if (!str || member_array(lower_case(str), ({"yes","y"})) == -1)
        {
        tell_object(this_player(),"������һ��, ���ǲ�Ҫ��.\n");
        tell_room(environment(this_player()),
        (string)this_player()->query("c_name")+"������ɫ, ˵��: "+
        "��... ���... ���뻹������.\n",({this_player(), this_object()}));
        command("kick "+(string)this_player()->query("name"));
        command("say ����������! û�²�Ҫ����.. С���� Z..A..P ���!");
        command("grin");
    set("wait"); // clear wait stat
        return 1;
        }
    set("wait"); // clear wait stat
    tell_object(this_player(),"��˵��: ��Ը��!\n");
    tell_room(environment(this_player()),(string)this_player()->query("c_name")+
    "˵��: "+"��Ը��!\n",({this_player(), this_object()}));
    if ((int)query("step")==1) { // ask the girl
        perform_marriage2();
        set("step",2);
        return 1;
    }
    if ((int)query("step")==2) { // here we go
        perform_marriage3();
        set("step",3); // set to 3 until finish this
        return 1;
    }
    return 1;
}
void divorce_end()
{
    set("husband");
    set("wife");
    set("witness");
    set("male_agree",0);
    set("female_agree",0); 
    FARWIND"church.c"->divorce_end();
 
}

int perform_divorce()
{
      command("say �������Ҫ�����? ");
      command("say ����Ҫ���ؿ���һ��, ������ͬ��(agree),���Ǿܾ�(refuse)?");

      return 1;
}

int do_shake(string str)
{
    object ob1,ob2,wiz,me;
    string n1,n2;
    if((int)query("male_agree")==0 || (int)query("female_agree")==0) return 0;
    me=this_player();
    n1=(string)query("husband");
    n2=(string)query("wife");
    if(n1!=me->query("name") && n2!=me->query("name"))
    {
       command("slap "+(string)me->query("name"));
       command("say "+(string)me->query("c_name")+", �Ҳ�������!");
       return 1;        
    }
    if(n1==lower_case(me->query("name")) ) 
    {
       command("say "+capitalize(n1)+" ��ͬ�����, ���ʧ��!");
    }
    else
    {
       command("say "+capitalize(n2)+" ��ͬ�����, ���ʧ��!\n");
    }
    command("kick");
    command("spit");
    command("say û׼���þͱ�������, ��XX��!");
    divorce_end();
    return 1;
}
int do_nod(string str)
{
    object nolen,ob1,ob2,wiz,me,this_room;
    string n1,n2;
    if((int)query("male_agree")==0 || (int)query("female_agree")==0) return 0;
    me=this_player();
    n1=(string)query("husband");
    n2=(string)query("wife");

    if(n1!=me->query("name") && n2!=me->query("name"))
    {
       command("slap "+(string)me->query("name"));
       command("say "+(string)me->query("c_name")+", �Ҳ�������!");
        return 1;        
    }
    if(n1==me->query("name") ) 
    {
       command("say "+capitalize(n1)+"ͬ�������!");
       if( query("female_agree") <= 1 )
         command("say ��ô����, "+capitalize(n2)+"?");
       set("male_agree",2);
    }
    if(n2==me->query("name") ) 
    {
       command("say "+capitalize(n2)+"ͬ�������!");
       if( query("male_agree") <= 1)
         command("say ��ô����, "+capitalize(n1)+"?");
       set("female_agree",2);
    }
    if(query("male_agree")>1 && query("female_agree")>1)
    {
       this_room=environment(this_object());
       wiz=present(query("witness"),this_room);
       ob1=present(n1,this_room);
       ob2=present(n2,this_room);
       if(!ob1 || !ob2 || !wiz)
       {
          command("say �˲�ȫ���޷�������ȥ!\n");
          divorce_end();
          return 1;
       }
       command("shout "+capitalize(n1)+"��"+capitalize(n2)+"�����!");
       if((string)wiz->query("name")=="moon")
command("shout "+"�ǲ���"+capitalize(n2)+"�����˷������ε�"+wiz->query("c_name"));
       else
command("shout "+wiz->query("c_name")+"Ϊʲô��ô����������֤��, �ǲ������˵�����!");
      
       ob1->delete("spouse");
       ob2->delete("spouse");
       divorce_end();
       return 1;
     }
     return 1;
}
