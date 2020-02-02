/**
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
* IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef QFT_CORE_I_CHECK_DATA_HXX
#define QFT_CORE_I_CHECK_DATA_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// ===========================================================
// TYPES
// ===========================================================

namespace qft
{

    namespace core
    {

    // -----------------------------------------------------------

    /**
      * @brief
      * ICheckData - interface for data control check object (file or stream).
      * Due to veriety of algorithms (CRC-32/16/8/4, SHA-512/256/128) for data-check, this interface used to
      * separate specific-logic from core.
      *
      * @version 0.1
      * @authors Denis Z. (code4un@yandex.ru)
    **/
    class ICheckData
    {

    public:

        // -----------------------------------------------------------

        // ===========================================================
        // DESTRUCTOR
        // ===========================================================

        /**
          * @brief
          * ICheckData destructor.
          *
          * @throws - can throw exception:
          *   - access-violation;
          *   - mutex;
        **/
        virtual ~ICheckData()
        {
        }

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        // ===========================================================
        // METHODS
        // ===========================================================

        /**
          * @brief
          * Check if control-data match given source.
          *
          * @throws - can throw exception:
          *   - numeric/algorithm;
          *   - mutex;
          *   - access-violation;
          * @returns - 'true' if control-data is valid (CRC, SHA-256).
        **/
        virtual bool IsValid() = 0;

        // -----------------------------------------------------------

    }; /// qft::core::ICheckData

    // -----------------------------------------------------------

    } /// core

} /// qft
using qftICheckData = qft::core::ICheckData;
#define QFT_CORE_I_CHECK_DATA_DECL

// -----------------------------------------------------------

#endif // !QFT_CORE_I_CHECK_DATA_HXX
