import java.io.FileInputStream;
import java.security.KeyStore;
import java.security.cert.X509Certificate;
import javax.xml.crypto.dsig.XMLSignContext;
import javax.xml.crypto.dsig.XMLSignatureFactory;
import javax.xml.crypto.dsig.dom.DOMSignContext;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;

public class Test {
   public static void main(String[] args) throws Exception {

   try{
      String keyStoreFileName = args[0];
      String keyEntryPasswd = args[1];
      char[] keyStorePasswd = "rototo".toCharArray(); 

      //Load the KeyStore and get the signing key and certificate
      KeyStore ks = KeyStore.getInstance("JKS");
      ks.load(new FileInputStream(keyStoreFileName), keyStorePasswd);
      
      System.out.printf("1\n");
      KeyStore.PrivateKeyEntry keyEnt = (KeyStore.PrivateKeyEntry) ks.getEntry("wowza", new KeyStore.PasswordProtection(keyEntryPasswd.toCharArray()));   // -> ERROR IN THIS ROW
      System.out.printf("2\n");

      X509Certificate cert = (X509Certificate)keyEnt.getCertificate();

      }catch(Exception e){
        e.printStackTrace();
        throw new Exception(e.toString());
      } 
   }       
}

