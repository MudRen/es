#include "farwind.h"
#define MARRIAGE_FILE "d/noden/data/marriages.o"

inherit ROOM;

string *couples, *pending;
int i, j, numcouples, numpending;
string str ;


void create()
{
        ::create();
        seteuid(getuid()) ;
    set("objects", ([ "priest" : FARWIND"monster/nolen" ]) );
//    set("objects", ([ "priest" : "/u/e/elon/nolen" ]) );
    reset() ;
        set ("light", 1) ;
    set_short("����");
    set_long(@TEXT
����һ��СС�Ľ���, ���������⻬��ʯש, ���컨�����������Ĺ�ʹ��
���濴����������. ����ǽ�Ϲ���һЩ������ʽ����, ����һƬǽ�Ͽ�������
������������Ͻ�Ϊ���޵�����. ��ǰ����һ����̨, �Ա�����һ����ʾ��(sign).

TEXT
    );
        set("exits", ([ "south" : FARWIND"ebazz" ]) );
    set("item_desc", ([
//    "wall" : "@@list_couples",
    "sign" : @SIGN
�鿴�ѽ�������:

couples

��ν��:
����, �Ҹ�������. Ȼ���Ҹ���֤��,(ע: ������������ĳЩ�����ĵĹ�
��, ���ǻὨ������һ����ʦ�������ﵱ��֤��, �����������ֲ�Ҫ����ʦ
��֤����, ����Ҳ���ᷴ��).������������ɹ�֤������:
marry <�з�> <Ů��>
�������ʦ�ͻ�Ϊ�����ֻ�����.

ע: Ҫȡ������... �� cancel ָ��.
    ֻ�й�֤�˿���ȡ��һ������, �����֤�˲��ڳ����κ��˶�����ȡ��.

������:
    ������һλ��ʦ�������﹫֤���, ����(��)����:

    divorce <�з�> <Ů��>
�������ʦ�ͻ�Ϊ�����ֻ�����.
SIGN
    ]) );
//    numpending = 0 ;
//    pending = allocate(10) ;
        str = read_file(MARRIAGE_FILE,1,1) ;
        if (!str) {
                numcouples = 0 ;
                couples = allocate(1) ;
                return ;
        }
        if (sscanf(str,"%d",numcouples)!=1) {
        write ("��... ǽ�ϵ����е�ģ������, ����ø����ù�����Ա��һ��!\n") ;
                return ;
        }
        couples = allocate(numcouples+1) ;
        for (i=0;i<numcouples;i++) {
                str = read_file(MARRIAGE_FILE,i+2,i) ;
                sscanf (str,"%s\n",couples[i]) ;
        }
        set("busy",0);

}
void divorce_end()
{
    set("busy",0);
}
void init()
{
    add_action("setup_marriage", "marry");
    add_action("cancel_marriage", "cancel");
    add_action("list_couples", "couples");
    add_action("setup_divorce", "divorce");
}

int cancel_marriage()
{
    object ob;
    if (!query("witness")) return notify_fail("û�����ڽ��еĻ���!\n");
    ob=present(query("witness"),this_object());
    if ((string)this_player()->query("name")!=(string)query("witness"))
        {
        if (ob) {
                return notify_fail("��û��Ȩȡ���ⳡ����!\n");
        }
    }
    set("witness");
    tell_room(environment(this_player()), "����ȡ����!!\n", this_object());
    // clean up everything..
    ob=present("nolen",this_object());
    ob->set("husband");
    ob->set("wife");
    ob->set("witness");
    ob->set("step",1);
    ob->set("wait");
        set("busy",0);
    return 1;
}

int setup_marriage(string str)
{
    string n1,n2,n3;
    object ob1, ob2;
    if (!str) return notify_fail("�﷨: marry <�з�> <Ů��>\n");
    if ((int)query("busy") == 1) return 
      notify_fail("�������ڽ������... ���Ե�һ��!\n");
    if (sscanf(str,"%s %s",n1,n2)!=2) return
        notify_fail("�﷨: marry <�з�> <Ů��>\n");
    n3=(string)this_player()->query("name");
    if ((n3==lower_case(n1)) || (n3==lower_case(n2))) return
        notify_fail("���Լ�֤��? �������, û��Ҫ����֤�鰡?\n"+
            "ȥȥȥ... ·��ץ���������ᰡ.\n");
    ob1=present(lower_case(n1),this_object());
    ob2=present(lower_case(n2),this_object());
    if ((!ob1 || !ob2)) return notify_fail("��û�����ʲ��鰡?!\n");
    if (ob1->query("spouse") || ob2->query("spouse")) return
        notify_fail("��..... ����֮����һ���ѻ���... ���ǲ�Ҫ...\n");
    if (ob1->query("npc") || ob2->query("npc")) return
        notify_fail("��ֻ�ܰ����֤��.\n");
    if ( ((string)ob1->query("class") == "monk" && (int)ob1->query("18brass") != 2) ||
       ((string)ob2->query("class") == "monk" && (int)ob2->query("18brass") != 2) ) return
        notify_fail("���в��ܽ��! \n");
    ob1=present("nolen",this_object());
    if (!ob1) return notify_fail("�Ǹ�... ��ʦ����ż�. �����!\n");
    ob1->set("husband",lower_case(n1));
    ob1->set("wife",lower_case(n2));
    ob1->set("witness",this_player()->query("name"));
    set("witness",this_player()->query("name")); // for cencel
        set("busy",1);
    return ob1->perform_marriage();
}

int setup_divorce(string str)
{
    string n1,n2,n3;
    object ob1, ob2,me,nolen;
    seteuid(getuid());
    me=this_player();
    if ( !wizardp(me) ) return notify_fail("����������ʦΪ��֤��!\n");
    if (!str) return notify_fail("�﷨: divorce <�з�> <Ů��>\n");
    if ((int)query("busy") == 1) return 
      notify_fail("�������ڽ������... ���Ե�һ��!\n");
    if (sscanf(str,"%s %s",n1,n2)<2) return
        notify_fail("�﷨: divorce <�з�> <Ů��>\n");
    n3=(string)this_player()->query("name");
    n1=lower_case(n1);     n2=lower_case(n2);
    ob1=present(n1,this_object());
    ob2=present(n2,this_object());
    if(!ob1 && ! ob2) return notify_fail("û��Ҫ��鰡.... \n");
    nolen=present("nolen",this_object()); 
    if (!nolen) return notify_fail("�Ǹ�... ��ʦ����ż�. �����!\n");

    if(!ob1)
      if( lower_case(ob2->query("spouse"))==n1 )
       if(file_size("/data/std/connection/"+n1[0..0]+"/"+n1+".o")<0) 
       {
           tell_object(ob2,"ԭ����ż����, ����ס��?\n");
           tell_object(ob2,"�ðɣ� ����������Ը��!\n");
           shout(ob2->query("c_name")+"�Դ�ɥż����������, ���ڰ���סҪ�����!!!\n");
           tell_object(ob2,"����, �����Ը�����!\n");
           ob2->delete("spouse");
           return 1;
        }
      else  return notify_fail("����˫�������ڵı���ͬʱ����! \n");
    
    if(!ob2)
      if( lower_case(ob1->query("spouse"))==n2 )
       if(file_size("/data/std/connection/"+n2[0..0]+"/"+n2+".o")<0) 
       {
           tell_object(ob1,"ԭ����ż����, ����ס��?\n");
           tell_object(ob1,"�ðɣ� ����������Ը��!\n");
           shout(ob1->query("c_name")+"�Դ�ɥż����������, ���ڰ���סҪ�����!!!\n");
           tell_object(ob1,"����, �����Ը�����!\n");
           ob1->delete("spouse");
           return 1;
        }
      else  return notify_fail("����˫�������ڵı���ͬʱ����! \n");

    if(!ob1 || !ob2) return notify_fail("���ǲ����ô�������? \n");
    if (! ob1->query("spouse") || ! ob2->query("spouse")) return
        notify_fail("ι..... ��û���������?\n");
    if(lower_case(ob1->query("spouse"))==n2 && lower_case(ob2->query("spouse"))==n1)
    {
      if(ob1->query("gender")=="male") 
      {
        nolen->set("husband",n1);
        nolen->set("wife",n2);
      }
      else
      {
        nolen->set("husband",n2);
        nolen->set("wife",n1);
      }
      nolen->set("witness",me->query("name"));
      nolen->set("male_agree",1);
      nolen->set("female_agree",1);
      set("busy",1);

      return nolen->perform_divorce();

    }
    else return notify_fail("�������ɲ��Ƿ���Ŷ! \n");
    return 1;
}


int list_couples()
{
        int i ;
        string s1, s2, date ;

        if (numcouples==0) {
        write("���ڲ�û���κ���ʽ�Ǽǵķ��� ....�����...\n");
        return 1;
    }
        for (i=0;i<numcouples;i++) {
                sscanf( couples[i],"%s-%s %s",s1, s2, date);
                write( i + "." +s1+" �� "+s2+" � "+date+" ���.\n");
        }
    return 1;
}

int marriage_done(string n1, string n2)
{
        seteuid(getuid());
    shout("������Զ����Ľ������������ص������� .... \n"+
          "·���Ƕ���������������ϲ������� !! ף�� "+capitalize(n1)+" �� "+capitalize(n2)+
         " ��Զ�Ҹ����� !!��\n");
    couples[numcouples] = n1+"-"+n2+" "+ctime(time());
        numcouples++;
        set("witness");
        set("busy",0);
        rm(MARRIAGE_FILE) ;
        write_file(MARRIAGE_FILE, numcouples+"\n") ;
        for (i=0;i<numcouples;i++)
                write_file (MARRIAGE_FILE, couples[i]+"\n") ;
        return 1;
}
