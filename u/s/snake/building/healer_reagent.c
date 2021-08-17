#include <mudlib.h>
#define HERB_INFO "/d/healer/herb_info/"

inherit ROOM;

//nosave mapping current_herbs=([ ]) ;

void create()
{
	::create();
    set_short("������");
	set_long( @C_LONG_DESCRIPTION
��������ҽ����ҩ�ĵ����ң����������е���ҩ���߶�������������ʹ�ã���
���Կ���һ�Ŵ���̨������̨�Ϸ���һ�������ݸ�Ŀ��(book)�������Ҫ��ҩ��
���������Ķ�ǽ���й���ҩ��˵��(sign)����ǽ���Ǹ�ҩ��(closet), ��Ҫ��Ҫ
��ҽ���ǻ�ͨ����, ��Ҫ���ҩ�ĵ��˷Ѽ����á�����������ҽ���鷿��
C_LONG_DESCRIPTION
	);

	set( "item_desc", ([
		"book" : @LONG_BOOK
�Ȿ�����ݸ�Ŀ����һλ������ʱ��Ķ���ѧ����׫��ҩѧ���䣬����Բ鿴
(read)�Ȿ���ҩ����(list)��ҩ�Ľ�˵����(index)��
LONG_BOOK
,
                "sign" :@LONG_TEXT
Ҫ���Լ���ҩ, ����ҩ��ҩ��, ����Ҫ�Ļ����㱾��ҩ��ѧ(medical)
��֪ʶ���󲿷ݵ�ҩ�Ķ��������̴���ĵ�����, �����ٲ��ݺ�����
����Ҫ���Լ���Ұ��ɼ���
LONG_TEXT
,
                "closet":@CLOSET_DES
����רΪҽ�������ҩ��, ��Ҫ��Ϊ��ͨ����, ����ҽ���Ž�, ����ҩ��
���˷Ѷ������ġ� ������� get/store <herb> from/in closet, ����ȡ
ҩ�ġ� ������ search closet ������ҩ�ĵĴ��� ��
CLOSET_DES
 ]) );
 	set("light",1);

        set("current_herb",([ ])) ;

        set( "exits", ([
		"south" : "/d/healer/building/healer_inner" ]) );
	reset();
}

void init()
{
	    add_action( "do_read", "read" ) ;
        add_action( "do_store", "store" ) ;
        add_action( "do_get", "get" ) ;
        add_action( "do_search","search" ) ;
}

int do_store(string str)
{
     string  ob_name,ob_cname,ob_filename,ob_num,target  ;
     object  ob ;

     if (!str) return 0;
     if(sscanf(str,"%s in closet",ob_name)!=1) return 0 ;

     if( !(ob=present(ob_name,this_player())) )
         {
            write("������û�н�"+ob_name+"�Ķ�����\n") ;
            return 1 ;
          }
     if ( ! ob->query("ident") )
         {
           write("ֻ��ҩ�Ĳ��ܷŽ�ҩ����\n") ;
           return 1 ;
          }

     sscanf(file_name(ob),"%s#%s",ob_filename,ob_num);
     ob_filename=replace_string(ob_filename,"/","*");
     ob_cname = ob->query("c_name") ;

     this_object()->add("current_herb/"+ob_filename,1) ;
     ob->remove() ;

     tell_object(this_player(),
                  "���"+ob_cname+"�Ž�ҩ����\n") ;
     tell_room(environment(this_object()),
               this_player()->query("c_name")+"��"+ob_cname+"�Ž�ҩ����\n");
     return 1 ;
}

int do_get(string str)
{
     int     i,no,j,found,amount ;
     string  ob_name,ob_cname,*current_list,*ids,ob_filename  ;
     object  ob ;
     mapping herbs ;

     if(!str) return 0;
     if(sscanf(str,"%s from closet",ob_name)!=1) return 0 ;

     herbs = this_object()->query("current_herb") ;
     no = sizeof(herbs) ;

     if(!no||no==0)
        {
          write("����ҩ�����ǿյġ�\n") ;
          return 1 ;
         }
     current_list = keys(herbs) ;

     if (ob_name == "all") {
       for (i=0; i < no ; i ++) {
         ob_filename=replace_string(current_list[i],"*","/");
         amount=this_object()->query("current_herb/"+current_list[i]);
         ob=new(ob_filename) ;
         ob->move(this_player()) ;
         ob_cname = ob->query("c_name") ;
         for (j=0; j < amount; j++) {
           ob=new(ob_filename) ;
           ob->move(this_player()) ;
           ob_cname = ob->query("c_name") ;
           tell_object(this_player(),"���ҩ�����ó�"+ob_cname+"����\n") ;
           tell_room(environment(this_player()),
                     this_player()->query("c_name")+"��ҩ�����ó�"+
                     ob_cname+"����\n",this_player()) ;
         }
       }
       this_object()->delete("current_herb");
       return 1;
     }
     for(i=0;i<no;i++)
        {
           ob_filename=replace_string(current_list[i],"*","/");
           ob = find_object_or_load(ob_filename) ;
           ids = ob->query("id");
           found=0;
           for (j=0; j < sizeof(ids); j++) {
             if(ids[j]==ob_name) { found=1 ; break ; }
           }
           if (found==1) break;
           if(i==no-1)
              {
                tell_object(this_player(),"ҩ����û�����ֶ�����\n") ;
                return 1 ;
              }
        }
     no = this_object()->query("current_herb/"+current_list[i]);
     if(!no||no==0)
            return notify_fail("ҩ������û�����ֶ�����\n") ;

     if(no==1)
         this_object()->delete("current_herb/"+current_list[i]) ;
     else
         this_object()->add("current_herb/"+current_list[i],-1) ;

     ob=new(ob_filename) ;
     ob->move(this_player()) ;
     ob_cname = ob->query("c_name") ;

     tell_object(this_player(),"���ҩ�����ó�"+ob_cname+"����\n") ;

     tell_room(environment(this_player()),this_player()->query("c_name")+
               "��ҩ�����ó�"+ob_cname+"����\n",this_player()) ;

     return 1 ;
}

int do_search(string str)
{
     int i,no,amount ;
     string msg,ob_name,ob_cname,*current_list ;
     object ob ;
     mapping herbs ;

     if(str!="closet")
        {
          write("������ʲ�� ?\n") ;
          return 1 ;
         }
     herbs = this_object()->query("current_herb") ;
     no = sizeof(herbs) ;

     if(!no||no==0)
        {
          write("����ҩ�����ǿյġ�\n") ;
          return 1 ;
         }
     current_list = keys(herbs) ;
     msg = "�㿴�˿�ҩ��, �������µ�ҩ��Ȼ��������ڹ�����:\n" ;

     for(i=0;i<no;i++)
        {
           amount=this_object()->query("current_herb/"+current_list[i]);
           current_list[i]=replace_string(current_list[i],"*","/");
           ob = find_object_or_load(current_list[i]) ;
           ob_name  = ob->query("name") ;
           ob_cname = ob->query("c_name") ;

           ob_name=ob_cname+"("+ob_name+")";
           msg = msg+sprintf("%-30s����%3d��\n",ob_name,amount);

        }
     tell_object(this_player(),msg) ;

     return 1 ;
}

int do_read( string str )
{
	int page;

	if( !str || str=="" )
	    return notify_fail("��Ҫ��ʲ�ᶫ����\n");
	if( str=="list" ) {
		cat(	HERB_INFO"c_list");
		return 1;
	} else if( str=="index" ) {
		cat( HERB_INFO"c_index");
		return 1;
	} else if( sscanf(str, "page %d", page)==1 ) {
	  if ( file_exists(HERB_INFO"c_page" + page ) ){
		cat( HERB_INFO"c_page" + page );
		return 1;
          } else {
                cat( HERB_INFO"c_no_page") ;
                return 1;
          }
	}
}

int clean_up() { return 0; }
