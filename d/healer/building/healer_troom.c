#include <mudlib.h>
#include "/d/healer/healer.h"

#define DIV "...................."

inherit "/std/room/std_storage.c";

int view_note() ;
void create()
{
	::create();
        set_short("Healer's study room", "��ҽ���鷿");
	set_long(
@C_LONG_DESCRIPTION
������ҽ������֪ʶ�ĵط���ټ��Ŀտ�����, �ڿ����ߵ�ǽ�߶�������
���ù�����ҽ�߳�¼�ʼ�, ��¼�ĵá���������������ǽ, ���Ƿ���ȫ����
ҽ�������(closet)�� ��Ӧ���ܴ�������ҵ�������õ���, �����еõ����
�����֪ʶ�����м�һ�������Ͽ�����ϧ�����������֡�ԭ������Ҳ��ҽ����
Ϊ�չ�����ר�����õĴ����ҡ�����ϸһ��.. �ƺ��Ա���һ����(note)��
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
        set( "item_func", ([
 		"closet": "view_closet" 
 		           ]) );
	set( "exits", ([ 
		"north" : "/d/healer/building/healer_inner"
		       ]) );
	set( "max_amount",50) ;               //�����������������������ֵ
        set("weapon_res",({10,0}) );
    set("class_name","healer") ;           //����������ڹ�������, �������
	                                      //�ù����Ա�����õ�װ��.
	set("msg_arg","�ʺ�����");                                                     
//     reset();              //��..�����һ�������?....hch.
}

 int clean_up() {return 0; }

void init()
{
   ::init() ;
   add_action("do_read","read") ;
   add_action("view_closet","search") ;
}

string query_intro()
{
    string intro ;

    intro = "\t    ������ɶ�����½��Դ������ҽ�����ഫ��������һλ��Ϊ\n"
            "\t����硻��ҽ����ʼʹ�����Ƶķ������β���Ȼ�����������\n"
            "\t��ҽ����������Ӱȥ����,�йֲ��ĵط��ͳ��������м�,Ҳ˳��\n"
            "\t�̵�������ĵķ�����������ռ�ȫ��½��, ����û�˼�������\n"
            "\t�ټ������, �����Ŵ����wing�����˵����ʼ������\n"
            "\tȻ��ȴû������֤ʵ����˵�ʡ������Ҹ�����Ϊ, �����ҽ����\n"
            "\t���������Ǹ�ר�ŵ������˵�ɫ�ǡ�����֮�ӡ�һ���޻���\n"
            "\t                                �涫��ҽ  ������\n"
            "\n\n\t��һҳ���Ǳ��������(index)��\n"
            "\t���������ڸ�ҳ(page)�С�\n" ;
 
    return intro ; 
}

string query_index()
{
    int i,size ;
    string msg, *merid, *eff ;
    
    merid = ALL_POINTS->query_meridians()  ;
    eff = USE_POINTS->now_working()   ; 
    
    msg = "\t����:\n" ;    
    
    size = sizeof(merid) ;
    for(i=1;i<size;i++)        
       msg = msg + sprintf("%s%-20s%s%s%5d\n","\t\t",merid[i],DIV,"page",i) ;

    msg = msg + "\t��������֪�����õ�Ѩ��Ⱥ\n" ;
    size = sizeof(eff) ;
    for(i=0;i<size;i++)        
       msg = msg + sprintf("%s%-20s%s%s%5d\n","\t\t",eff[i],DIV,"page",i+100) ;
           
    return msg ;
                
}

string page_contain(int page)
{
    int i,size ;
    string msg,*merid_eff,describ ;
    
    i = page ; 
    if( page < 100 )
      {
        merid_eff = ALL_POINTS->query_meridians_by_no(page) ;
//        describ = ALL_POINTS->query_merid_describ(page) ;
       } 
    else
      {
        page =page - 100 ;
        merid_eff = USE_POINTS->query_eff_pts(page) ;
 //       describ = USE_POINTS->query_eff_describ(page) ;
       }     
    
    if(!merid_eff||(size=sizeof(merid_eff))==0)
       return "����Ȿ������������������ǰǰ����ȫ������,\n"
              "��������û������һҳ��\n" ;

    msg = sprintf("\t��%dҳ......%10s��Ѩ��Ⱥ, ��%dѨ\n",i,merid_eff[0],size-1) ; 
//    msg = msg + describ ;

    for( i=1 ; i<size ; i++ ) {
      if (stringp(merid_eff[i]))
      msg = msg + (string)sprintf("\t\t%s\n",merid_eff[i]) ;
    }       
    return msg ;
}

int do_read(string str)
{
    int page_no ;
    string arg ;
        
    if(!str)
      return notify_fail("�����ʲ�� ??\n") ;

    if(str=="�����Ҫ"||str=="book"||str=="bible")
      { 
       write(query_intro()) ;
       return 1;
      }   
      
    if(str=="index"||str=="����")   
      { 
       write(query_index()) ;
       return 1;
      }   
    else
      {
        if( sscanf(str,"%s %d",arg,page_no)==2 )
           {
             if(lower_case(arg) == "page" ) 
                write(page_contain(page_no)) ;    
            }
        else    
           { 
             if(lower_case(str)=="page")
                write("�������һҳ ??\n" ) ;
             else
               return notify_fail("�����ʲ�� ??\n") ;     
            }
      }  
    return 1 ;     
}

int view_closet(string arg)
{
  write(
"   ��������з��˷�, ���ֳ���һ���С� �����Ҫ ������(book)����,���\n"
"����ȱ��ȫ�ˡ�\n"
 )  ;
  return 1 ;
}
