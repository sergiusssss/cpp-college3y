#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <random>

class Printer;
class DocumentPDF;
class DocumentDOCX;
class DocumentSS;

class Document {
  public:
    virtual ~Document() = default;
    virtual std::uint32_t elements_count() = 0;
    virtual void visit(std::shared_ptr<Printer> p) = 0;
};

class Printer {
public:
  virtual ~Printer() = default;
  virtual void print_pdf(DocumentPDF& doc_pdf) = 0;
  virtual void print_docx(DocumentDOCX& doc_docx) = 0;
  virtual void print_ss(DocumentSS& doc_ss) = 0;
};

// class PrinterMatrix : public Printer{
//
// };
//
// class PrinterInkJet : public Printer{
//
// };

class DocumentPDF : public Document{
  public:
    DocumentPDF(std::uint32_t pec, std::uint32_t cec){
      m_pdf_elements_count = pec;
      m_common_elements_count = cec;
    };

    std::uint32_t elements_count() override {
      return m_pdf_elements_count + m_common_elements_count;
    }

    std::uint32_t pdf_elements_count(){
      return m_pdf_elements_count;
    }

    void visit(std::shared_ptr<Printer> p) override {
      p->print_pdf(*this);
    }

    private:
      std::uint32_t m_pdf_elements_count;
      std::uint32_t m_common_elements_count;
};

class DocumentDOCX : public Document{
  public:
  DocumentDOCX(std::uint32_t dec, std::uint32_t cec){
    m_docx_elements_count = dec;
    m_common_elements_count = cec;
  };

  std::uint32_t elements_count() override {
    return m_docx_elements_count + m_common_elements_count;
  }

  std::uint32_t docx_elements_count(){
    return m_docx_elements_count;
  }

  void visit(std::shared_ptr<Printer> p) override {
    p->print_docx(*this);
  }

private:
  std::uint32_t m_docx_elements_count;
  std::uint32_t m_common_elements_count;
};

class DocumentSS : public Document{
  public:
  DocumentSS(std::uint32_t sec, std::uint32_t cec){
    m_ss_elements_count = sec;
    m_common_elements_count = cec;
  };

  std::uint32_t elements_count() override {
    return m_ss_elements_count + m_common_elements_count;
  }

  std::uint32_t ss_elements_count(){
    return m_ss_elements_count;
  }

  void visit(std::shared_ptr<Printer> p) override {
    p->print_ss(*this);
  }

private:
  std::uint32_t m_ss_elements_count;
  std::uint32_t m_common_elements_count;
};

class PrinterLaser : public Printer{
public:
  void print_pdf(DocumentPDF& doc_pdf) override {
    std::cout << "print_pdf " << doc_pdf.elements_count() << " " << doc_pdf.pdf_elements_count() << std::endl;
  }
  void print_docx(DocumentDOCX& doc_docx) override {
    std::cout << "print_docx " << doc_docx.elements_count() << " " << doc_docx.docx_elements_count() << std::endl;
  }
  void print_ss(DocumentSS& doc_ss) override {
    std::cout << "print_ss " << doc_ss.elements_count() << " " << doc_ss.ss_elements_count() << std::endl;
  }
};

std::shared_ptr<Document> create_document(){
  std::random_device rd; // obtain a random number from hardware
  std::mt19937 gen(rd()); // seed the generator
  std::uniform_int_distribution<> distr_type(0, 2); // define the range
  std::uniform_int_distribution<> distr_type_elements(0, 100); // define the range
  std::uniform_int_distribution<> distr_cm_elements(100, 500); // define the range
  std::uint32_t type = distr_type(gen);

  switch(type){
    case 0: return std::make_shared<DocumentPDF>(distr_type_elements(gen), distr_cm_elements(gen));
    case 1: return std::make_shared<DocumentDOCX>(distr_type_elements(gen), distr_cm_elements(gen));
    case 2: return std::make_shared<DocumentSS>(distr_type_elements(gen), distr_cm_elements(gen));
    default: return nullptr;
  }
}

int main(){
  std::shared_ptr<Printer> printer = std::make_shared<PrinterLaser>();
  auto doc = create_document();
  // std::cout << doc->elements_count() << std::endl;
  doc->visit(printer);
  return 0;
}