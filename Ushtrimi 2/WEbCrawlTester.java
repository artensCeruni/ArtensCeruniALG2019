import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class WEbCrawlTester {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File file=new File(args[2]);   //krijoj skedarin me emrin qe marr nga perdoruesi
		PrintWriter fw=new PrintWriter(file);
		
		Queue<String> a=new LinkedList<>();
		Crawler crawler=new Crawler(args[0]);  //krijoj objektin crawler me linkun fillestar
		
		
		
		
		for(int i=0; i<Integer.parseInt(args[1]); i++) {
			crawler.crawl();   //zbatoj kerkimin me thellesine e kerkuar
		}
		
		int counter=0;
		Set<String> c=new HashSet<>();
		c=crawler.getVizit();   ///marr te gjth linket e vizituar dhe i vendos ne nje set
		for(String x : c) {
			counter++;
			fw.println(counter+".\t"+x);   //i shkruaj ne skedar te gjith linket e vizituar
		}
		fw.println();
		fw.println("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
		fw.println("Linket e gjetura me thellesi "+args[1]+"ne faqen "+args[0]+"\n"+"Nr Total: "+counter);
		fw.println("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
		fw.close();
	}

}

