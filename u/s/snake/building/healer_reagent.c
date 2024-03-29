#include <mudlib.h>
#define HERB_INFO "/d/healer/herb_info/"

inherit ROOM;

//nosave mapping current_herbs=([ ]) ;

void create()
{
	::create();
    set_short("调剂室");
	set_long( @C_LONG_DESCRIPTION
这里是行医者配药的调剂室，在这里所有的配药工具都可以让你自由使用，你
可以看到一张大工作台，工作台上放著一本「本草纲目」(book)。如果你要配药的
话，请先阅读墙上有关配药的说明(sign)，靠墙则是个药橱(closet), 主要是要
让医生们互通有无, 不要造成药材的浪费及滥用。往南走是行医者书房。
C_LONG_DESCRIPTION
	);

	set( "item_desc", ([
		"book" : @LONG_BOOK
这本「本草纲目」是一位叫做李时珍的东方学者所撰的药学经典，你可以查看
(read)这本书的药方表(list)或药材解说索引(index)。
LONG_BOOK
,
                "sign" :@LONG_TEXT
要想自己制药, 除了药方药材, 最重要的还是你本身药物学(medical)
的知识。大部份的药材都可以在刑大娘的店里买到, 但有少部份罕见的
便需要你自己到野外采集。
LONG_TEXT
,
                "closet":@CLOSET_DES
这是专为医生而设的药橱, 主要是为互通有无, 增进医生团结, 避免药材
的浪费而设立的。 你可以用 get/store <herb> from/in closet, 来存取
药材。 或是用 search closet 来看看药材的存量 。
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
            write("你身上没有叫"+ob_name+"的东西。\n") ;
            return 1 ;
          }
     if ( ! ob->query("ident") )
         {
           write("只有药材才能放进药橱。\n") ;
           return 1 ;
          }

     sscanf(file_name(ob),"%s#%s",ob_filename,ob_num);
     ob_filename=replace_string(ob_filename,"/","*");
     ob_cname = ob->query("c_name") ;

     this_object()->add("current_herb/"+ob_filename,1) ;
     ob->remove() ;

     tell_object(this_player(),
                  "你把"+ob_cname+"放进药橱。\n") ;
     tell_room(environment(this_object()),
               this_player()->query("c_name")+"把"+ob_cname+"放进药橱。\n");
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
          write("现在药橱里是空的。\n") ;
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
           tell_object(this_player(),"你从药橱中拿出"+ob_cname+"来。\n") ;
           tell_room(environment(this_player()),
                     this_player()->query("c_name")+"从药橱中拿出"+
                     ob_cname+"来。\n",this_player()) ;
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
                tell_object(this_player(),"药橱中没有那种东东。\n") ;
                return 1 ;
              }
        }
     no = this_object()->query("current_herb/"+current_list[i]);
     if(!no||no==0)
            return notify_fail("药橱里面没有那种东东。\n") ;

     if(no==1)
         this_object()->delete("current_herb/"+current_list[i]) ;
     else
         this_object()->add("current_herb/"+current_list[i],-1) ;

     ob=new(ob_filename) ;
     ob->move(this_player()) ;
     ob_cname = ob->query("c_name") ;

     tell_object(this_player(),"你从药橱中拿出"+ob_cname+"来。\n") ;

     tell_room(environment(this_player()),this_player()->query("c_name")+
               "从药橱中拿出"+ob_cname+"来。\n",this_player()) ;

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
          write("你想找什麽 ?\n") ;
          return 1 ;
         }
     herbs = this_object()->query("current_herb") ;
     no = sizeof(herbs) ;

     if(!no||no==0)
        {
          write("现在药橱里是空的。\n") ;
          return 1 ;
         }
     current_list = keys(herbs) ;
     msg = "你看了看药橱, 看到以下的药井然有序的躺在柜子中:\n" ;

     for(i=0;i<no;i++)
        {
           amount=this_object()->query("current_herb/"+current_list[i]);
           current_list[i]=replace_string(current_list[i],"*","/");
           ob = find_object_or_load(current_list[i]) ;
           ob_name  = ob->query("name") ;
           ob_cname = ob->query("c_name") ;

           ob_name=ob_cname+"("+ob_name+")";
           msg = msg+sprintf("%-30s还有%3d个\n",ob_name,amount);

        }
     tell_object(this_player(),msg) ;

     return 1 ;
}

int do_read( string str )
{
	int page;

	if( !str || str=="" )
	    return notify_fail("你要读什麽东东？\n");
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
